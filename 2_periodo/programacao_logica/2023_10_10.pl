feminino(maria).
feminino(ana).
feminino(julia).
feminino(iris).

masculino(joao).
masculino(jose).
masculino(jorge).

progenitor(maria, jose).
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).

filho(X, Y) :- 
    progenitor(Y, X).

avo(X, Z) :-
    progenitor(X, Y),
    progenitor(Y, Z).

irmao(X, Y) :-
    progenitor(Z, X),
    progenitor(Z, Y).

mae(X, Y) :-
    progenitor(X, Y),
    feminino(X).

pai(X, Y) :-
    progenitor(X, Y),
    masculino(X).

antepassado(X, Z) :-
    progenitor(X, Z).
antepassado(X, Z) :-
    progenitor(X, Y),
    antepassado(Y, Z).