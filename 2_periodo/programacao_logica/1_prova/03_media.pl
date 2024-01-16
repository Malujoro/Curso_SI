soma([], 0) :- !.
soma([H | T], R) :-
    soma(T, R2),
    R is H + R2.

media(L, M, S) :-
    soma(L, R),
    M is R/4,
    ((M < 5.0, S = 'Reprovado', !);
    (M < 6.9, S = 'Recuperação', !);
    (M >= 7.0, S = 'Aprovado')).