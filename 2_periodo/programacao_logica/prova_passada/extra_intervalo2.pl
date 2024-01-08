verificaIntervalo(A, B, R) :-
    A < B,
    R = A,
    write(R), nl,
    A2 is A+1,
    verificaIntervalo(A2, B, R2).
