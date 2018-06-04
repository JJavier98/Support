% Autor: Daniel Soto y Juanjo Jiménez
% Fecha: 07/06/2014

% Listas

lista([]).
lista([L|Lr]):- lista(Lr).

miembro(L,[L|Lr]).
miembro(L,[M|Mr]):- miembro(L,Mr).

elimina(L,[L|Ls],Ls).
elimina(L,[M|Ms],[M|Ns]):- elimina(L,Ms,Ns).

comienza([],L).
comienza(L,[L|Lr]).
comienza([L|Lr],[L|Mr]):- comienza(Lr,Mr).

permutacion([],[]).
permutacion(Lr,[L|Mr]):- elimina(L,Lr,Nr), permutacion(Nr,Mr).

suma([],0).
suma([L|Lr],S):- suma(Lr,Sr), S is Sr+L.

producto([],1).
producto([L|Lr],S):- producto(Lr,Sr), S is Sr*L.

longitud([],0).
longitud([L|Lr],S):- longitud(Lr,Sr), S is Sr+1.

% Crecer
creciente([]).
creciente([L]).
creciente([L,L|Mr]):- L = L, creciente([L|Mr]).
creciente([L,M|Mr]):- L < M, creciente([M|Mr]).

% Decrecer
decreciente([]).
decreciente([L]).
decreciente([L,L|Mr]):- L = L, decreciente([L|Mr]).
decreciente([L,M|Mr]):- L > M, decreciente([M|Mr]).

% Máximo elemento de una lista
maximo([L],L).
maximo([L|Nr],L):- maximo(Nr,Y), L >= Y.
maximo([L|Nr],M):- maximo(Nr,M), M > L.

% Mínimo elemento de una lista
minimo([L],L).
minimo([L|Nr],L):- minimo(Nr,Y), L =< Y.
minimo([L|Nr],M):- minimo(Nr,M), M < L.

% Predicado corte
a(X):- b(X).
b(X):- !,d(X),e(X),f(X).
a(1).
b(2).
d(3). e(3). f(3).
d(4). e(4). f(4).

ifThenElse(Cond,X,Y):-call(Cond),!,call(X).
ifThenElse(Cond,X,Y):-call(Y).

numero(X):- X >= 0.
primopequeño(2).
primopequeño(3).
primopequeño(5).
primopequeño(7).
bueno(X):- primopequeño(X),!,fail.
bueno(X):- numero(X).

par(X):- 0 is X mod 2.
solopares([],[]).
solopares([L|Ls],Ms):- ifThenElse(par(L), Ms=[L|Ns], Ms=Ns), solopares(Ls,Ns).