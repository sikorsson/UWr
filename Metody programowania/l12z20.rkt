#lang racket

;; Współpraca: Michał Sobecki, Piotr Gunia, Paweł Sikora, Dominik Komła

;;Komentarz ćwiczeniowca:
;;Rozwiązanie niezgodne z zaleceniem - wielokrotne użycie bag-peek na kolejce z pustą drugą listą będzie wielokrotnie odwracać pierwszą listę. Konstruktor opisany we wskazówce zapewnia, że prawa lista dla niepustej kolejki jest zawsze niepusta.

(require "graph.rkt")
(provide bag-stack@ bag-fifo@)

;; struktura danych - stos
(define-unit bag-stack@
  (import)
  (export bag^)
  (define (bag? s)
    (list? s))
  (define empty-bag null)
  (define (bag-empty? s)
    (null? s))
  (define (bag-insert s b)
    (cons b s))
  (define (bag-peek s)
    (car s))
  (define (bag-remove s)
    (cdr s)))

;; struktura danych - kolejka FIFO
(define-unit bag-fifo@
  (import)
  (export bag^)
  (define (bag? s)
    (and (pair? s)
         (list? (car s))
         (list? (cdr s))))
  (define empty-bag (cons null null))
  (define (bag-empty? s)
    (and (bag? s)
         (null? (car s))
         (null? (cdr s))))
   (define (bag-insert s b)
     (cons (cons b (car s)) (cdr s))) 
  (define (bag-remove s)
    (let ([fr (car s)]
          [bc (cdr s)])
    (cond
      [(null? bc) (cons null (cdr (reverse fr)))]
      [else (cons fr (cdr bc))])))
  (define (bag-peek s)
    (let ([fr (car s)]
          [bc (cdr s)])
    (cond
      [(null? bc) (car (reverse fr))]
      [else (car bc)]))))

;; otwarcie komponentów stosu i kolejki

(define-values/invoke-unit bag-stack@
  (import)
  (export (prefix stack: bag^)))

(define-values/invoke-unit bag-fifo@
  (import)
  (export (prefix fifo: bag^)))

;; testy w Quickchecku
(require quickcheck)

;; testy kolejek i stosów
(define-unit bag-tests@
  (import bag^)
  (export)
  
  ;; test przykładowy: jeśli do pustej struktury dodamy element
  ;; i od razu go usuniemy, wynikowa struktura jest pusta
  (quickcheck
   (property ([s arbitrary-symbol])
             (bag-empty? (bag-remove (bag-insert empty-bag s)))))

  ;; czy dodany elementy jest tym samym na wyjściu
  (quickcheck
   (property ([s arbitrary-symbol])
             (equal? s (bag-peek (bag-insert empty-bag s)))))

  ;; czy po dodaniu 2 elementów wyjściowy będzie równy pierwszemu / nie zachodzi dla fifo
  (quickcheck
   (property ([s1 arbitrary-symbol]
              [s2 arbitrary-symbol])
             (equal? s1 (bag-peek (bag-insert (bag-insert empty-bag s2) s1)))))
  
  ;; czy po dodaniu 2 elementów i usunięciu 1 wyjściowy będzie równy drugiemu / nie zachodzi dla fifo
  (quickcheck
   (property ([s1 arbitrary-symbol]
              [s2 arbitrary-symbol])
             (equal? s2 (bag-peek (bag-remove (bag-insert (bag-insert empty-bag s2) s1))))))

   ;; czy po dodaniu 2 elementów wyjściowy będzie równy pierwszemu /  nie zachodzi dla stosu
  (quickcheck
   (property ([s1 arbitrary-symbol]
              [s2 arbitrary-symbol])
             (equal? s2 (bag-peek (bag-insert (bag-insert empty-bag s2) s1)))))

   ;; czy po dodaniu 2 elementów i usunięciu 1 wyjściowy będzie równy pierwszemu / nie zachodzi dla stosu
  (quickcheck
   (property ([s1 arbitrary-symbol]
              [s2 arbitrary-symbol])
             (equal? s1 (bag-peek (bag-remove (bag-insert (bag-insert empty-bag s2) s1))))))

  
)

;; uruchomienie testów dla obu struktur danych

(invoke-unit bag-tests@ (import (prefix stack: bag^)))
(invoke-unit bag-tests@ (import (prefix fifo: bag^)))

;; otwarcie komponentu grafu
(define-values/invoke-unit/infer simple-graph@)

;; otwarcie komponentów przeszukiwania 
;; w głąb i wszerz
(define-values/invoke-unit graph-search@
  (import graph^ (prefix stack: bag^))
  (export (prefix dfs: graph-search^)))

(define-values/invoke-unit graph-search@
  (import graph^ (prefix fifo: bag^))
  (export (prefix bfs: graph-search^)))

;; graf testowy
(define test-graph
  (graph
   (list 1 2 3 4)
   (list (edge 1 3)
         (edge 1 2)
         (edge 2 4))))

(define test-graph2
  (graph
   (list 1 2 3 4 5)
   (list (edge 1 2)
         (edge 2 3)
         (edge 3 1)
         (edge 1 4)
         (edge 4 5)
         (edge 5 1))))

(define test-graph3 ;; na podstawie grafiki z google
  (graph
   (list 1 2 3 4 5 6 7)
   (list (edge 1 2)
         (edge 1 3)
         (edge 1 4)
         (edge 2 6)
         (edge 2 7)
         (edge 3 5)
         (edge 4 3)
         (edge 4 5)
         (edge 5 2)
         (edge 7 5))))

(define test-graph4 ;; na podstawie grafiki z google
  (graph
   (list 1 2 3 4 5 6)
   (list (edge 1 2)
         (edge 1 3)
         (edge 2 4)
         (edge 2 5)
         (edge 3 6))))

;; uruchomienie przeszukiwania na przykładowym grafie
(bfs:search test-graph 1)
(dfs:search test-graph 1)

(bfs:search test-graph2 1)
(dfs:search test-graph2 1)

(bfs:search test-graph3 1)
(dfs:search test-graph3 1)

(bfs:search test-graph4 1)
(dfs:search test-graph4 1)