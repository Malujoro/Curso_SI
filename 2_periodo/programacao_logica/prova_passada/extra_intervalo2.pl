verificaIntervalo(A, B, R) :-
    A < B,
    R = A,
    A2 is A+1,
    write(R), nl,
    verificaIntervalo(A2, B, R2).
