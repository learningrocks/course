;;sum-list
(define (sum-list num-list)
  (if (null? num-list) 0
    (+ (car num-list)
       (sum-list (cdr num-list)))))

(display (sum-list '(1 2 3 4 5)))

;;fib
(define (fib n)
  (if (or (= n 0)
          (= n 1)) n
    (+ (fib (- n 1))
       (fib (- n 2)))))

(display (fib 10))

;;flatten, in c/c++ is very difficult, 50% memory management. 50% for algorithm
(define (flatten sequence)
  (cond ((null? sequence) '())
        ((list? (car sequence)) (append (flatten (car sequence))
                                        (flatten (cdr sequence))))
        (else (cons (car sequence) (flatten (cdr sequence))))))


(flatten '((1) (2 3 4) (5 6)))

;;sorted
(define (sorted? num-list)
  (or (< (length num-list) 2)
      (and (<= (car num-list)
               (cadr num-list))
           (sorted? (cdr num-list)))))

(sorted? '(1 2 3 4 7))
;; #t

(define (sorted1? seq comp)
  (or (< (length seq) 2)
      (and (comp (car seq)
                 (cadr seq))
           (sorted!? (cdr seq) comp))))

