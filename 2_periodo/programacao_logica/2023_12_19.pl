not(X) :- (X, !, fail) ; true.

teste(X) :-
    X, !.

humano(joao).