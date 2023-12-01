membro(X, [X | _]).
membro(X, [_ | T]) :-
    membro(X, T).

concatenar([], L, L).
concatenar([X | L1], L2, [X | L3]) :-
    concatenar(L1, L2, L3).

remove(X, [X | L], L).
remove(X, [Y | L], [Y | L2]) :-
    remove(X, L, L2).

tamanho([], 0) :- !.
tamanho([_ | T], N) :-
    tamanho(T, N2),
    N is 1 + N2.

fatorial(0, 1) :- !.
fatorial(N, R) :-
    N2 is N-1,
    fatorial(N2, R2),
    R is N * R2.

fibonacci(0, 0).
fibonacci(1, 1).
fibonacci(N, R) :-
    N1 is N-1,
    N2 is N-2,
    fibonacci(N1, R1),
    fibonacci(N2, R2),
    R is R1 + R2.

posicao(X, [X | _], 1) :- !.
posicao(X, [_ | Z], P) :-
    posicao(X, Z, P1),
    P is 1 + P1.