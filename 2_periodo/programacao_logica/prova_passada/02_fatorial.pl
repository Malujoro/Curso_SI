fatorial(0, 1).
fatorial(N, R) :-
    N1 is N-1,
    fatorial(N1, R1),
    R is N * R1,
    !.