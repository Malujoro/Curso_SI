verificaIntervalo(A, B, R) :-
    A < B,
    ((R is A); A1 is A+1, verificaIntervalo(A1, B, R)).
