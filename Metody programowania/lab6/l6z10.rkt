#lang racket

(provide (struct-out complex) parse eval)

(struct complex (re im) #:transparent)

(define value?
  complex?)

;; Ponizej znajduje sie interpreter zwyklych wyrazen arytmetycznych.
;; Zadanie to zmodyfikowac go tak, by dzialal z liczbami zespolonymi.

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)
(struct variable ()    #:transparent)

(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /]))

(define (square x) (* x x))

(define (eval e)
  (match e
    [(const n) (complex n 0)]
    [(variable) (complex 0 1)]
    [(binop '+ l r) 
                    (let ((left (eval l))
                           (right (eval r)))
                    (complex (+ (complex-re left) (complex-re right))
                             (+ (complex-im left) (complex-im right))))]
    [(binop '- l r) 
                    (let ((left (eval l))
                           (right (eval r)))
                    (complex (- (complex-re left) (complex-re right))
                             (- (complex-im left) (complex-im right))))]
    [(binop '* l r) 
                    (let ((left (eval l))
                           (right (eval r)))
                    (complex (- (* (complex-re left) (complex-re right)) (* (complex-im left) (complex-im right)))
                             (+ (* (complex-re left) (complex-im right)) (* (complex-im left) (complex-re right)))))]
    [(binop '/ l r) 
                    (let ((left (eval l))
                           (right (eval r))
                           (mod (+ (square (complex-re (eval r))) (square (complex-im (eval r))))))
                    (complex (/ (+ (* (complex-re left) (complex-re right)) (* (complex-im left) (complex-im right))) mod)
                             (/ (- (* (complex-im left) (complex-re right)) (* (complex-re left) (complex-im right))) mod)))]
    ))

(define (parse q)
  (cond [(number? q) (const q)]
        [(eq? q 'i) (variable)]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse (second q)) (parse (third q)))]))

(eval (parse '(* i i))) ;i^2
(eval (parse '(+ 3 (* i 8)))) ;3+8i
(eval (parse '(/ (+ 1 (* 8 i)) (+ 2 (* 3 i))))) ;(1+8i)/(2+3i)
(eval (parse '(* (+ 5 (* 2 i)) (- 3 (* 7 i))))) ;(5+2i)*(3-7i)