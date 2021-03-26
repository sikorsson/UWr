#lang racket

(provide (all-defined-out))

(define (lcons x f) (mcons x f))
(define lnull null)
(define lnull? null?)
(define (lcar xs) (mcar xs))
(define (lcdr xs) (cond
                    [(mpair? (mcdr xs)) (mcdr xs)]
                    [else (set-mcdr! xs ((mcdr xs))) (mcdr xs)]))

(define (from n)
  (lcons n (lambda () (from (+ n 1)))))

(define nats
  (from 0))

(define (lnth n xs)
   (cond [(= n 0) (lcar xs)]
         [else (lnth (- n 1) (lcdr xs))]))

(define (lfilter p xs)
  (cond [(lnull? xs) lnull]
        [(p (lcar xs))
         (lcons (lcar xs) (lambda () (lfilter p (lcdr xs))))]
        [else (lfilter p (lcdr xs))]))

(define (prime? n)
  (define (factors i)
    (cond [( >= i n) (list n)]
          [(= (modulo n i) 0) (cons i (factors (+ i 1)))]
          [else (factors (+ i 1))]))
  (= (length (factors 1)) 2))

(define primes (lfilter prime? (from 2)))

(time (lnth 1000 primes))
(time (lnth 1001 primes))
(time (lnth 1002 primes))