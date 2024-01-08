conectado(a, c).
conectado(a, d).

conectado(b, d).
conectado(b, e).

conectado(c, f).

conectado(e, g).

conectado(f, h).


caminho(X, Y) :-
    conectado(X, Y), !.
caminho(X, Z) :-
    conectado(X, Y),
    caminho(Y, Z).