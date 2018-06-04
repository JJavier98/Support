% Práctica 8
% Laura Tirado López

% Definición de una lista ( es recursiva)
% Caso base: lista vacía
lista([]).

% Caso recursivo: si Ls es una lista, [L|Ls] es una lista con cabeza L y cola Ls
lista([L|Lr]):- lista(Lr).

/**************************************************************************************/
/**************************************************************************************/

% Función para compobar si un elemento pertenece o no a una lista
% Caso base: el elemento es la cabeza
miembro(L,[L|Lr]).

% Caso recursivo: si el elemento no es la cabeza, lo buscamos en la cola
miembro(L,[M|Mr]):- miembro(L,Mr).

/**************************************************************************************/
/**************************************************************************************/

% Función para eliminar un elemento
% Caso base: el elemento a eliminar es la cabeza, se devuelve la cola
elimina(L,[L|Ls],Ls).

% Caso recursivo: si el elemento a eliminar no es la cabeza, estará en la cola
elimina(L,[M|Ms],[M|Ns]):- elimina(L,Ms,Ns).

/**************************************************************************************/
/**************************************************************************************/

% Función para comprobar si una lista comienza por un elemento o lista dada
% Caso base: si le damos una lista vacía
comienza([],L).
% Caso base: que la lista dada coincida con la cabeza de la lista
comienza(L,[L|Lr]).

% Caso recursivo: si la cabeza de ambas coincide, se sigue mirando en la cola
comienza([L|Lr], [L|Mr]):- comienza(Lr,Mr).

/**************************************************************************************/
/**************************************************************************************/

% Función para comprobar si una lista terminar por un elemento o lista dada
% Caso base: le damos una lista vacía
termina([],L).
% caso base: la cola coincide.
termina(Lr,[L|Lr]).

% si la cola no coincide, buscamos en ella
termina(Lr,[L|Mr]):- termina(Lr,Mr).

/**************************************************************************************/
/**************************************************************************************/

% Función para buscar los elementos pares de una lista
% Definimos las funciones par e impar
par(X):- 0 is X mod 2.
impar(X):- 1 is X mod 2.

% Caso base: que ambas listas sean vacías
pares_de([],[]).

% Caso recursivo: si la cabeza coincide y es par, buscamos en la cola
pares_de([L|Lr],[L|Mr]):- par(L), pares_de(Lr,Mr).
% Caso recursivo: si la cabeza no coincide y es impar, buscamos en la cola
pares_de([L|Lr],Mr):- impar(L), pares_de(Lr,Mr).

/**************************************************************************************/
/**************************************************************************************/

% Función para sumar los elementos de una lista
% Caso base: lista vacía 
suma([],0).

% Caso recursivo: vamos sumando la cabeza
suma([L|Lr],S):- suma(Lr,Sr), S is Sr+L.

/**************************************************************************************/
/**************************************************************************************/

% Función para calcular las posibles permutaciones de una lista
% caso base: lista vacía
permutacion([],[]).

% Caso recursivo: vamos elimnando un elemento cada vez con la función elimina
permutacion(Lr, [L|Mr]):- elimina(L,Lr,Nr), permutacion(Nr,Mr).

/**************************************************************************************/
/**************************************************************************************/

% Ejercicio 2: 
% Dar definiciones para producto de los elementos de una lista y longitud de una lista, así
% como predicados para detectar cuando una lista es creciente, tiene un máximo, un mínimo o primero
% crece y luego decrece (hace montaña) o primero decrece y luego crece (hace valle).

% Producto:
% caso base: lista vacía
producto([],[]).

% Caso recursivo:
producto([L|Lr],P):- producto(Lr,Pr), P is Pr*L.

% Longitud:
% Caso base: lista vacía
longitud([],0).

% Caso recursivo:
longitud([L|Lr],Le):- longitud(Lr,Ler), Le is Ler+1.

% Creciente:
% caso base: lista vacía
creciente([]).
creciente([L]).

% Caso recursivo:
creciente([L,M|Mr]):- L < M, creciente([M|Mr]).


/**************************************************************************************/
/**************************************************************************************/

% Ejemplo de predicado de corte
% La primera vez ejecutará toda la regla b(x), 
% la segunda sólo ejecutará hasta la "!"
a(X):- b(X).
b(X):- d(X),!,e(X),f(X).
a(1).
b(2).
d(3). e(3). f(3).
d(4). e(4). f(4).


