#lang racket

;Komentarz ćwiczeniowca:
;Wywołuje Pan w procedurze mergesort procedurę split dwa razy z tym samym argumentem - w efekcie komputer liczy dwa razy, niepotrzebnie, ten sam wynik.
;Ponadto zdefiniował Pan procedurę split niezgodnie ze specyfikacją zadania - miała zwracać parę list, a zwraca listę list.

;algorytm napisany z wykorzystaniem źródeł:
;https://docs.racket-lang.org/guide/Pairs__Lists__and_Racket_Syntax.html
;https://blog.racket-lang.org/2012/08/fully-inlined-merge-sort.html
;https://learningtogetolder.wordpress.com/2013/06/14/merge-sort-in-racket/
;i stackoverflow

(require rackunit)
(require rackunit/text-ui)

(define (merge left right)
  (if (null? right)
      left
      (if (null? left)
          right
          (if (> (car left) (car right))
              (cons (car right) (merge (cdr right) left))
              (cons (car left) (merge (cdr left) right))))))

(define (split l)
  (if (null? l)
      (list '() '())
      (if (null? (cdr l))
          (list l '())
          (let ([rest (split (cdr (cdr l)))])
            (list (cons (car l) (car rest))
                  (cons (car (cdr l)) (car (cdr rest))))))))

(define (mergesort l)
  (if (null? l)
      null
      (if (null? (cdr l))
          l
          (merge (mergesort (car (split l)))
                 (mergesort (car (cdr (split l))))))))

(provide merge split mergesort)

(define mergesort-test
  (test-suite
   "test"
   (check-equal? (merge '(1) '(2))
                 (list 1 2))
   (check-equal? (split '(1 2 3 4))
                 (list (list 1 3) (list 2 4)))
   (check-equal? (mergesort '(5 4 3 2 1 0))
                 (list 0 1 2 3 4 5))))

(run-tests mergesort-test)