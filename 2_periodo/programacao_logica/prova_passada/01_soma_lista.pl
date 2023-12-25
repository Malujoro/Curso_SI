somaLista([], 0).
somaLista([X | T], R) :-
    somaLista(T, R2),
    R is X + R2.