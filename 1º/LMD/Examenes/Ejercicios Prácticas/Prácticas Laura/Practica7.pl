% Práctica 7
% Laura Tirado López


% Ejemplo: programita endulza

% Definimos un hecho
endulza(azucar,cafe).
endulza(azucar,zumo).
endulza(azucar,leche).

% Definimos la función
es_dulce(X):-endulza(_,X).



% Ejemplo1
%	Una base de conocimiento de prolog
%	acaba_de_comer(X,Y) son hechos
%	esta_digiriendo(X,Y) son reglas que tiene en cuenta los hechos
%	definidos
%	es recursiva

acaba_de_comer(mosquito,sangre(pedro)).
acaba_de_comer(mosquito,nectar).
acaba_de_comer(mosquito,savia).
acaba_de_comer(pez,mosquito).
acaba_de_comer(serpiente,pez).
acaba_de_comer(oso,pez).
acaba_de_comer(aguila,serpiente).
acaba_de_comer(rana,mosquito).
acaba_de_comer(garza,rana).
acaba_de_comer(aguila,perdiz).
acaba_de_comer(perdiz,trigo).

esta_digiriendo(X,Y):- acaba_de_comer(X,Y).
esta_digiriendo(X,Y):- acaba_de_comer(X,Z), esta_digiriendo(Z,Y).


% Ejercicio 1
% Programar una base de conocimiento Prolog con los hechos y reglas dados por el árbol
% genealógico de tu familia, tomando 3 generaciones hacia atrás y considerando hermanos y los dos
% progenitores en todos los casos. Utilizar los predicados padre/2, madre/2, progenitor/2,
% hombre/1, mujer/1, tio/2, tia/2, Primo_hermano/2, Prima_hermana/2 y definir una
% función recursiva antepasado/2.

% Primero definimos los hechos

es_padre(juan,jose).
es_padre(juan,juanito).
es_padre(francisco,juan).
es_padre(francisco,teresa).
es_padre(francisco,inmaculada).
es_padre(jose,carmen).
es_padre(jose,miguel).
es_padre(alberto,teresa).
es_padre(julio,francisco).
es_padre(julio,aurora).
es_padre(julio,nazaret).
es_padre(roberto,jose).
es_padre(roberto,abel).
es_padre(roberto,nuria).
es_padre(gregorio,maria).
es_padre(gregorio,ana).


es_madre(carmen,jose).
es_madre(carmen,juanito).
es_madre(isabel,teresa).
es_madre(teresa,juan).
es_madre(teresa,inmaculada).
es_madre(teresa,teresa).
es_madre(maria,carmen).
es_madre(maria,miguel).
es_madre(julia,francisco).
es_madre(julia,aurora).
es_madre(julia,nazaret).
es_madre(clara,jose).
es_madre(clara,abel).
es_madre(clara,nuria).
es_madre(pilar,maria).
es_madre(pilar,ana).


es_tia(inmaculada,jose).
es_tia(inmaculada,juanito).
es_tia(teresa,jose).
es_tia(teresa,juanito).
es_tia(aurora,juan).
es_tia(aurora,teresa).
es_tia(aurora,inmaculada).
es_tia(nazaret,juan).
es_tia(nazaret,teresa).
es_tia(nazaret,inmaculada).
es_tia(nuria,carmen).
es_tia(nuria,miguel).


es_tio(miguel,jose).
es_tio(miguel,juanito).
es_tio(abel,carmen).
es_tio(abel,miguel).

son_progenitores(teresa,francisco).
son_progenitores(jose,maria).
son_progenitores(julio,julia).
son_progenitores(alberto,isabel).
son_progenitores(roberto,clara).
son_progenitores(gregorio,pilar).
son_progenitores(carmen,juan).


% Función recursiva
es_antepasado(X,Y):- es_padre(X,Y); es_madre(X,Y); es_tio(X,Y); es_tia(X,Y).
es_antepasado(X,Y):- es_padre(X,Z), es_antepasado(Z,Y); es_madre(X,Z), es_antepasado(Z,Y); es_tio(X,Z), es_antepasado(Z,Y); es_tia(X,Z), es_antepasado(Z,Y).



% Ejemplo hechos y cláusulas

p(X):-q(X),r(x).

p(X):-u(X).

q(X):-s(X).

r(a).
r(b).

s(a).
s(b).
s(c).

u(d).


% Ejemplo 6
% Dadas las siguientes afirmaciones:
%
%• Hace buen tiempo.
%• Es viernes.
%• Juan tiene suerte si es verano.
%• No es verano.
%• Juan tiene suerte si es viernes y hace buen tiempo.
%• Antonio es un malvado.
%• Juan es un malvado.
%• Toda persona malvada y con suerte gana a la ruleta.

% Describir un Lenguaje de Primer Orden adecuado para representar los
% enunciados y, con el orden dado por las cláusulas por su orden de
% aparición en el enunciado anterior, escribir el “script”
% correspondiente a las cláusulas en Prolog y contestar a la pregunta:
% ¿Quién gana a la ruleta?

% Dominio:
%D = {personas, días de la semana, estaciones del año, {bueno,malo}}.

t(b).
dia(v).
suerte(juan):-est(ver).
suerte(juan):-t(b),dia(v).
est(no_ver).
malvado(antonio).
malvado(juan).

gana(X):-malvado(X),suerte(X). 

% Ejemplo 7
%
% Prolog puede no encontrar soluciones si el orden en el que están dadas las 
% y hechos no es el correcto.

a:-a.
a.

% No encuentra respuesta a la pregunta a., ya que entra en una rama infinita
% Sin embargo la solución existe.

% Ejemplo 9
% Dadas las siguientes afirmaciones:
%
% • Los hermanos menores de mis admiradores son mis admiradores (válido
% para cualquier persona).
%• Todas las personas son admiradoras de sí mismas.
%• Pepe es hermano menor de Juan.
%
% Describir un Lenguaje de Primer Orden adecuado para representar los
% enunciados y, con el orden dado por las cláusulas por su orden de
% aparición en el enunciado anterior, escribir el “script”
% correspondiente a las cláusulas en Prolog y contestar a la pregunta:
% ¿Quién admira a Juan?.

% Para que el script funcione primero se definen los hechos y después
% las reglas, si no la resolución de Prolog no será correcta

hermano_menor(pepe,juan).

admira(X,X).
admira(X,Z):-hermano_menor(X,Y),admira(Y,Z).

% Ejercicio 3
% Poner de manifiesto con 3 preguntas al sistema las diferencias entre is, =, =:= . 
%
% El operador is sirve tanto para unificar(asignar valores a constantes) como
% para comprobar igualdades.
% El operador = sólo sirve para unificar pero no evalua.
% El operador =:= sólo evalúa una expresión.

% Ejemplo 10
% Vamos a implementar una función factorial

% Caso base
fact(0,1).

% Función recursiva
fact(N,F):- N>0, N1 is N-1, fact(N1,F1), F is N*F1.

% Ejercicio 4
% Hacer un script en Prolog que calcule la función de Fibonacci, utilizando recursión.

% Casos base
fibonacci(1,1).
fibonacci(2,1).

% Función recursiva
fibonacci(A,X):- A >= 2, B is A-1, fibonacci(B,Y), C is A-2, fibonacci(C,Z), X is Y+Z.