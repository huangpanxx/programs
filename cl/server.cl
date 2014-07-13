(load "~/quicklisp/setup.lisp")
(ql:quickload "hunchentoot")


(hunchentoot:start (make-instance 'hunchentoot:easy-acceptor :port 8000))

(hunchentoot:define-easy-handler (say-yo :uri "/yo")  (name)
  (setf (hunchentoot:content-type*) "text/plain")
  (format nil "Hey~@[ ~A~]!" name))


(hunchentoot:define-easy-handler (home :uri "") ()
  (setf (hunchentoot:content-type*) "text/plain")
  (format nil "hello"))
