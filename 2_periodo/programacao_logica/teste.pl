progenitor(maria, jose). 
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).
masculino(joao).  
masculino(jose).
masculino(jorge).
feminino(maria). 
feminino(ana).
feminino(julia).
feminino(iris).


filho(Y, X) :- 
    progenitor(X, Y). 

mae(X, Y) :- 
    progenitor(X, Y), 
    feminino(X). 

avo(X, Z) :- 
    progenitor(X, Y), 
    progenitor(Y, Z). 

irma(X, Y) :- 
    progenitor(Z, X), 
    progenitor(Z, Y),
    feminino(X), 
    X \= Y. 

irmao(X, Y) :- 
    progenitor(Z, X), 
    progenitor(Z, Y),
    masculino(X), 
    X \= Y. 

tio(X,Z) :-
    irmao(X,Y),
    filho(Z,Y),
    masculino(X).

prima(X,Y):- progenitor(Z,Y),progenitor(W,X),irmao(W,Z),feminino(X).

conjugue(X,Y) :- progenitor(X,Z), progenitor(Y,Z).


antepassado(X, Z) :-
    progenitor(X, Z). 
antepassado(X, Z) :- 
    progenitor(X, Y), 
    antepassado(Y, Z). 
