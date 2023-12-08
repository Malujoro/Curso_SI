adiciona(X, [], [X]).
adiciona(X, [H1|T1], [H2|T2]) :-
    H2 is H1,
    adiciona(X, T1, T2).

apaga(X, [X|T], T).
apaga(X, [H|T], [H2|T2]) :-
    H2 is H,
    apaga(X, T, T2).

membro(X, [X|_]).
membro(X, [_|T]) :-
    membro(X, T).

concatena([], L2, L2).
concatena([H1|T1], L2, [H3|T3]) :-
    H3 is H1,
    concatena(T1, L2, T3).

tamanho(0, []).
tamanho(Tam, [_|T]) :-
    tamanho(Tam2, T),
    Tam is 1 + Tam2.