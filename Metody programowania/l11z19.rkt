#lang racket

(provide (contract-out
          [with-labels with-labels/c]
          [foldr-map foldr-map/c]
          [pair-from pair-from/c]))
(provide with-labels/c foldr-map/c pair-from/c)

(require racket/contract)

(define (with-labels e l)
    (if (null? l)
        null
  (cons (list (e (car l)) (car l)) (with-labels e (cdr l)))))


(define (foldr-map f a xs) ; przerobiony kod z listy zadań
  (define (it a xs ys)
    (if (null? xs)
        (cons ys a)
        (let [(p (f (car xs) a))]
          ( it (cdr p)
               (cdr xs)
               (cons (car p) ys)))))
  (it a (reverse xs) null))

(define (pair-from f g)
  (lambda (x) (cons (f x) (g x))))

(define with-labels/c (parametric->/c [a b] (-> (-> a b) (listof a) (listof (list/c b a)))))

(define foldr-map/c (parametric->/c [a b c] (-> (-> a b (cons/c c b)) b (listof a) (cons/c (listof c) b))))

(define pair-from/c (parametric->/c [a b c] (-> (-> c a) (-> c b) (-> c (cons/c a b)))))



(with-labels number->string (list 1 2 3))

(foldr-map (lambda (x a) (cons a (+ a x))) 0 '(1 2 3))

((pair-from (lambda (x) (+ x 1)) (lambda (x) (* x 2))) 2)