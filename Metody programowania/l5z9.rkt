#lang racket
;Współpraca: Szymon Rysz, Michał Sobecki, Paweł Sikora

;Funkcje pomocnicze:
;---------------------------------------------------------------------------
(require "props.rkt")
(provide falsifiable-cnf?)

(define (lit? f)
  (or (var? f)
      (and (neg? f)
           (var? (neg-subf f)))))

(define (lit-pos v)
  v)

(define (lit-neg v)
  (neg v))

(define (lit-var l)
  (if (var? l)
      l
      (neg-subf l)))

(define (lit-pos? l)
  (var? l))

(define (to-nnf f)
  (cond
   [(var? f)  (lit-pos f)]
   [(neg? f)  (to-nnf-neg (neg-subf f))]
   [(conj? f) (conj (to-nnf (conj-left f))
                    (to-nnf (conj-right f)))]
   [(disj? f) (disj (to-nnf (disj-left f))
                    (to-nnf (disj-right f)))]))

(define (to-nnf-neg f)
  (cond
   [(var? f)  (lit-neg f)]
   [(neg? f)  (to-nnf (neg-subf f))]
   [(conj? f) (disj (to-nnf-neg (conj-left f))
                    (to-nnf-neg (conj-right f)))]
   [(disj? f) (conj (to-nnf-neg (disj-left f))
                    (to-nnf-neg (disj-right f)))]))

(define (mk-cnf xss)
  (cons 'cnf xss))

(define (clause? f)
  (and (list? f)
       (andmap lit? f)))

(define (cnf? f)
  (and (pair? f)
       (eq? 'cnf (car f))
       (list? (cdr f))
       (andmap clause? (cdr f))))

(define (to-cnf f)
  (define (join xss yss)
    (apply append (map (lambda (xs) (map (lambda (ys) (append xs ys)) yss)) xss)))
  (define (go f)
    (cond
     [(lit? f)  (list (list f))]
     [(conj? f) (append (go (conj-left f))
                        (go (conj-right f)))]
     [(disj? f) (join (go (disj-left f))
                      (go (disj-right f)))]))
  (mk-cnf (go f)))

;Funkcja falsifiable-cnf? i funkcje pomocnicze:
;---------------------------------------------------------------------------
(define (eval-clause clause v)
  (if (null? clause)
      #f
      (or (if (lit-pos? (car clause))
              (second (assoc (car clause) v))
              (not (second (assoc (cadar clause) v))))
          (eval-clause (cdr clause) v))))

(define (falsifiable-clause? clause)
#|funkcja bierze klauzule jako argument i zwraca wartościowanie:
  jeśli zmienna nie była zanegowana: jej wartościowanie to #f
  wpp. jej wartościowanie to #t
  dopuszczone jest pojawienie się dwóch różnych wartościowań dla tej samej zmiennej,
  ponieważ funkcja eval-clause używa procedury assoc, dzięki czemu przy ewaluacji
  klauzuli, nawet gdy dla danej zmiennej będą dwa różne wartościowania,
  zostanie wybrane to, które występuje na liście jako pierwsze|#
  
  (define (maybe-false clause v)
    (if (null? clause)
        v
        (if (lit-pos? (car clause))
            (maybe-false (cdr clause) (append v (list (list (car clause) #f))))
            (maybe-false (cdr clause) (append v (list (list (cadar clause) #t)))))))
  (let ([falsify-vals (maybe-false clause (list))])
    (if (not (eval-clause clause falsify-vals))
        falsify-vals
        #f)))
      
(define (falsifiable-cnf? f)
  (let* ([nnf-formula (to-nnf f)]
         [cnf-formula (to-cnf nnf-formula)])
    (define (falsifiable-cnf-helper f)
      (if (null? f)
          #f
          (let ([falsify-vals (falsifiable-clause? (car f))])
              (if (eq? #f falsify-vals)
              (falsifiable-cnf-helper (cdr f))
              falsify-vals))))
    (falsifiable-cnf-helper (cdr cnf-formula))))
      
;Kilka testów:
;---------------------------------------------------------------------------

(falsifiable-cnf? (disj (conj 'p 'z) (disj 'r 'q)))
(falsifiable-cnf? (disj (conj (neg 'p) 'z) (disj (neg 'r) 'q)))
(falsifiable-cnf? (conj (conj (conj 'p 'z) (disj 'r 'q)) (disj 'p 'q)))
(falsifiable-cnf? (disj (disj 'p (neg 'p)) 'z))
(falsifiable-cnf? 'p)
(falsifiable-cnf? (disj (conj 'p 'q) (conj (neg 'p) 'q)))


;Funkcje potrzebne do standardowego sprawdzania czy formuła jest tautologią:
;---------------------------------------------------------------------------
(define (free-vars f)
    (define (go f)
        (cond ((var? f)
               (list f))
              ((neg? f)
               (go (neg-subf f)))
              ((disj? f)
               (append (go (disj-left f)) 
                       (go (disj-right f))))
              ((conj? f)
               (append (go (conj-left f)) 
                       (go (conj-right f))))))
    (remove-duplicates (go f)))

(define (gen-vals xs)
  (if (null? xs)
      (list null)
      (let*
          ((vss  (gen-vals (cdr xs)))
           (x    (car xs))
           (vst  (map (lambda (vs) (cons (list x true)  vs)) vss))
           (vsf  (map (lambda (vs) (cons (list x false) vs)) vss)))
        (append vst vsf))))

(define (eval-formula f v)
    (cond
        ((var? f) (second (assoc f v)))
        ((neg? f) (not (eval-formula (neg-subf f) v)))
        ((conj? f) (and
            (eval-formula (conj-left f) v)
            (eval-formula (conj-right f) v)))
        ((disj? f) (or
            (eval-formula (disj-left f) v)
            (eval-formula (disj-right f) v)))
    ))

(define (falsifiable-eval? f)
    (define (is-false v)
        (not (eval-formula f v)))
    (let* [
        (vars (free-vars f))
        (all-vals (gen-vals vars))
        (false-vals (filter is-false all-vals))
        ]
        (if (= (length false-vals) 0)
            false
            (first false-vals))))


;Porównanie czasu działania funkcji falsifiable-cnf? i falsifiable-eval?:
;---------------------------------------------------------------------------
"falsifiable-cnf:"
(time (falsifiable-cnf? (conj (conj (conj (conj (conj 'i 'j) (conj'e 'f)) (conj 'a 'b)) (conj'p 'q)) (conj (conj (conj (conj 'k 'l) (conj 'g 'h)) (conj (conj 'm 'n) (conj 'p 'q))) (conj 'c 'd)))))
"falsifiable-eval?"
(time (falsifiable-eval? (conj (conj (conj (conj (conj 'i 'j) (conj'e 'f)) (conj 'a 'b)) (conj'p 'q)) (conj (conj (conj (conj 'k 'l) (conj 'g 'h)) (conj (conj 'm 'n) (conj 'p 'q))) (conj 'c 'd)))))
"falsifiable-cnf?"
(time (falsifiable-cnf? (disj (disj (disj (disj (disj 'i 'j) (disj'e 'f)) (disj 'a 'b)) (disj'p 'q)) (disj (disj (disj (disj 'k 'l) (disj 'g 'h)) (disj (disj 'm 'n) (disj 'p 'q))) (disj 'c 'd)))))
"falsifiable-eval?"
(time (falsifiable-eval? (disj (disj (disj (disj (disj 'i 'j) (disj'e 'f)) (disj 'a 'b)) (disj'p 'q)) (disj (disj (disj (disj 'k 'l) (disj 'g 'h)) (disj (disj 'm 'n) (disj 'p 'q))) (disj 'c 'd)))))

;Obserwacje i wnioski:
;---------------------------------------------------------------------------
#|
Funkcja falsifiable-cnf? daje wynik znacząco szybciej, ponieważ wyznacza
jedno wartościowanie dla każdej klauzuli, w której w większości przypadków
będzie tylko kilka zmiennych występujących w formule, a nie wszystkie.
W najbardziej pesymistycznym przypadku formułą w CNF
będzie jedna klauzula zawierająca wszystkie zmienne występujące w formule.
Wtedy czas działania funkcji będzie proporcjonalny do liczby zmiennych
(+ czas poświęcony na konwersje do NNF a następnie do CNF).
W większości przypadków klauzule nie będą zawierały wszystkich zmiennych,
więc wynik otrzymamy, gdy tylko funkcji uda się sfalsyfikować którąś klauzulę.

Funkcja falsifiable-eval? ma złożoność wykładniczą. Dla formuły,
która ma n zmiennych, funkcja ta musi wygenerować 2^n wartości
i w najbardziej pesymistycznym przypadku sprawdzić wynik formuły
dla każdego wartościowania.
|#