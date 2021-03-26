#lang racket

(define (square x)
  (* x x))

(define (abs x)
  (if (< x 0)
      (- x)
      x))

(define (good-enough? x y)
    (< (abs (- x y)) 0.0001))

;;funkcje powyżej z podręcznika

(define (next_val N D n-1 n-2 k) ;;wzór z treści
  (+ (* (D k) n-1) (* (N k) n-2)))

(define (cont-frac num den)
  (define (fk A B An+1 Bn+1 n)
    (if (good-enough? (/ A B) (/ An+1 Bn+1))
        (/ A B)
        (fk An+1 Bn+1 (next_val num den An+1 A (+ n 1)) (next_val num den Bn+1 B (+ n 1)) (+ n 1))))
    (fk 0.0 1.0 (next_val num den 0.0 1.0 1) (next_val num den 1.0 0.0 1) 1))

(define (arctan x) ;; z ćw 8
  (cont-frac (lambda (n)
           (if (= n 1)
               x
               (square (* (- n 1) x))))
      (lambda (n)
        (- (* 2 n) 1))))

(provide cont-frac)

(arctan 0)
(atan 0)
(arctan 3)
(atan 3)
(arctan 7)
(atan 7)
(arctan 10)
(atan 10)
(arctan 13)
(atan 13)
(arctan 17)
(atan 17)