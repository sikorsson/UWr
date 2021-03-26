#lang racket

(define (dist x y)
  (abs (- x y)))


(define (compose f g) (lambda (x) (f (g x))))

(define (identity x) x)

(define (repeated p n)
  (lambda (x)
    (if(= n 0)
    (identity x)
    ((compose (repeated p (- n 1)) p) x))))


(define (good-enough? x y)
  (< (dist x y) 0.0001))

(define (fixed-point f x0)
  (let ((x1 (f x0)))
    (if (good-enough? x0 x1)
        x0
        (fixed-point f x1))))

(define (average-damp f)
  (lambda (x) (/ (+ x (f x)) 2)))

;;funkcje powyżej z podręcznika, zajęć



(define (nth-root n x)
  (fixed-point
      ((repeated average-damp (floor (log x 2)))
          (lambda (y) (/ n (expt y (- x 1))))) 1.0))


(provide nth-root)

;;liczba tłumień wynosi log2 z n
(nth-root 4 2)(floor (log 2 2))
(nth-root 128 4)(floor (log 4 2))
(nth-root 256 8)(floor (log 8 2))
(nth-root 512 9)(floor (log 9 2))
(nth-root 1024 10)(floor (log 10 2))
(nth-root 65536 16)(floor (log 16 2))
;;liczbę tłumień można zauważyć wprowadzając kolejne liczby naturalne i program zapętla się dla kolejnych potęg 2
;;dlatego liczba tłumień wynosi log2 z n