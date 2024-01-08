membro(X, [X | _]) :- !.
membro(X, [_ | T]) :-
    membro(X, T).

tamanho([], 0) :- !.
tamanho([_ | T], Quant) :-
    tamanho(T, Quant2),
    Quant is 1 + Quant2.

soma([], 0) :- !.
soma([H | T], R) :-
    soma(T, R2),
    R is H + R2.

apaga(X, [X | T], T) :- !.
apaga(X, [H | T], [H | T1]) :-
    membro(X, T),
    apaga(X, T, T1).

concatena([], Lista2, Lista2) :- !.
concatena([H | T], Lista2, [H | T3]) :-
    concatena(T, Lista2, T3).

add(X, [], [X]) :- !.
add(X, [H | T], [H | T2]) :-
    add(X, T, T2).

posicao(X, [X | _], 1) :- !.
posicao(X, [_ | T], Pos) :-
    membro(X, T),
    posicao(X, T, Pos2),
    Pos is 1 + Pos2.

media(Lista, Tot) :-
    soma(Lista, Soma),
    tamanho(Lista, Tamanho),
    Tot is Soma/Tamanho.

primeiro(X, [X | _]) :- !.

ultimo(X, [X]) :- !.
ultimo(X, [_ | T]) :-
    ultimo(X, T).

consecutivos(X, Y, [X, Y | _]) :- !.
consecutivos(X, Y, [_ | T]) :- 
    consecutivos(X, Y, T).

consecutivos_lista([X | T], [X2 | T2]) :- 
    (
        X =:= X2,
        consecutivos_lista2(T, T2)
    );
    consecutivos_lista([X | T], T2).

consecutivos_lista2([X | []], [X | _]).
consecutivos_lista2([X | T], [X | T2]) :- 
    consecutivos_lista2(T, T2).

% Ex 03 - Crie uma regra que recebe uma lista e retorna outra lista somente com os pares.

pares([], []) :- !.
pares([H | T], [H2 | T2]) :-
    (
        0 is H mod 2,
        H2 = H,
        pares(T, T2)
    );
    (
        pares(T, [H2 | T2])
    ).

inverte([X], [X]) :- !.

inverte([X | T], L2) :-
    inverte(T, T2),
    add(X, T2, L2).