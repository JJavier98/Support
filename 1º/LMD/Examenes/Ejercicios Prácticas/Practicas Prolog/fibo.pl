% Autor: Daniel Soto Del Ojo y Juanjo Jim�nez
% Fecha: 03/06/2014
% Clase: 1�A - A1

% Ejercicio 2

% Fibonacci
fib(1,1).
fib(2,1).
fib(N,R):-N>2,N1 is N-1,N2 is N-2,fib(N1,R1),fib(N2,R2),R is R1+R2.

% Cuadrado
fibcuadrado(N,R):-N1 is N,fib(N1,R1), R is R1*R1.

% Fibleft
fibleft(N,R):-N1 is N,N2 is N+1,fibcuadrado(N1,R1),fibcuadrado(N2,R2),
              R is R1+R2.

% Fibright
fibright(N,R):-N1 is 2*N+1,fib(N1,R1), R is R1.

% fib2
fib2(N):-fibleft(N,R1),fibright(N,R1).

% Ejercicio 3

rec(0,1).
rec(1,2).
rec(2,4).
rec(N,R):-N>2, N1 is N-1,N2 is N-2,N3 is N-3,rec(N1,R1),rec(N2,R2),rec(N3,R3),
          R is R1*R2*R3.
          
tribonacci(N,R):-N>2, N1 is N-1,N2 is N-2,N3 is N-3,rec(N1,R1),
                 rec(N2,R2),rec(N3,R3), R is log(R1*R2*R3)/log(2).
                 
% Ejercicio 4
% Xn+3 = 3Xn+2 - 3Xn+1 + Xn ---> Xn = 3Xn-1 - 3Xn-2 + Xn-3

suc(0,0).
suc(1,1).
suc(2,4).
suc(N,R):-N>2,N1 is N-1,N2 is N-2,N3 is N-3,suc(N1,R1),suc(N2,R2),
          suc(N3,R3), R is 3*R1 - 3*R2 + R3.