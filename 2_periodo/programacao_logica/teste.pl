divisivel(N, N) :- !.
divisivel(A, B) :-
    0 is A mod B.

somaImpar([], 0).
somaImpar([X | T], R) :-
    somaImpar(T, R2),
    (
        (1 is X mod 2,
        R is R2 + X)
        ;
        R is R2
    ).

somaPar([], 0).
somaPar([X | T], R) :-
    somaPar(T, R2),
    (
        (0 is X mod 2,
        R is X + R2)
        ;
        R is R2
    ).

somaLista([], 0).
somaLista([X | T], R) :-
    somaLista(T, R2),
    R is X + R2.

separaLista([], [], []) :- !.
separaLista([X | T], [X | T2], Impar) :- 
    0 is X mod 2,
    separaLista(T, T2, Impar).
separaLista([X | T], Par, [X | T3]) :-
    1 is X mod 2,
    separaLista(T, Par, T3).

membro(X, [X | _]) :- !.
membro(X, [_ | T]) :-
    membro(X, T).

membroLista(X, L1, L2) :-
    membro(X, L1), membro(X, L2), write('Está nas duas listas'), !
    ;
    membro(X, L1), write('Está apenas na primeira'), !
    ;
    membro(X, L2), write('Está apenas na segunda'), !
    ;
    write('Não está em nenhuma'), !.