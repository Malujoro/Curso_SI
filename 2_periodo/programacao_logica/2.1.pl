arco(a, b, 3).
arco(b, d, 2).
arco(d, a, 5).

arco(a, c, 4).
arco(c, d, 4).

arco(d, e, 2).
arco(e, f, 2).
arco(f, c, 5).

diferente(X, Y) :-
    X \= Y.

mais(X, Y, Z) :-
    Z is X + Y.

custo(U, V, L) :-
    (arco(U, V, L) ; arco(V, U, L)), 
    diferente(U, V).

custo(U, V, L) :-
    diferente(U, V),
    (custo(U, X, R) ; custo(X, U, R)),
    (custo(X, V, Z) ; custo(V, X, Z)),
    mais(R, Z, L).