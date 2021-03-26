#lang racket

(provide (struct-out const) (struct-out binop) rpn->arith)

;; -----
;; Stack
;; -----

(struct stack (xs))

(define empty-stack (stack null))
(define (empty-stack? s) (null? (stack-xs s)))
(define (top s) (car (stack-xs s)))
(define (push a s) (stack (cons a (stack-xs s))))
(define (pop s) (stack (cdr (stack-xs s))))

;; -------------------------------
;; Wyrazenia w odwr. not. polskiej
;; -------------------------------

(define (rpn-expr? e)
  (and (list? e)
       (pair? e)
       (andmap (lambda (x) (or (number? x) (member x '(+ - * /))))
               e)))

;; ----------------------
;; Wyrazenia arytmetyczne
;; ----------------------

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)

(define (arith-expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r)
     (and (symbol? op) (arith-expr? l) (arith-expr? r))]
    [_ false]))

;; ----------
;; Kompilacja
;; ----------

(define (rpn->ar e s)
  (cond [(null? e) (top s)]
    [(number? (car e))
     (rpn->ar (cdr e) (push (const (car e)) s))]
    [(symbol? (car e))
     (let ((right (top s))
           (left (top (pop s))))
     (rpn->ar (cdr e)
                 (push (binop (car e) left right) (pop (pop s)))))]
    ))

(define (rpn->arith e) (rpn->ar e empty-stack))

(rpn->arith '(1 1 +))
(rpn->arith '(2 3 4 * +))
(rpn->arith '(8 7 * 1 3 * +))
(rpn->arith '(12 2 / 2 3 * -))
