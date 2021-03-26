#lang racket

;algorytm na podstawie tego z podrecznika

(define (sqr x)
  (* x x))

(define (cube x)
  (* x (sqr x)))

(define (dist x y)
  (abs (- x y)))

(define (abs x)
  (if (< x 0)
      (- x)
      x))
(provide cube-root)

(define (cube-root x)
  (define (improve guess)
    (/ (+ (/ x (sqr guess)) (* 2 guess)) 3))

  (define (good-enough? g)
    (< (dist x (cube g))
       0.000001))

  (define (iter guess)
    (if (good-enough? guess)
        guess
        (iter (improve guess))))
  
  (iter 1.0))

(cube-root 8)
(cube-root 27)
(cube-root 15)
(cube-root 1000)
(cube-root 125)