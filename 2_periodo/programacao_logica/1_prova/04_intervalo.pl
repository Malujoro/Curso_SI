gerar_intervalo(A, B, []) :- A > B.
gerar_intervalo(A, B, [H | T]) :-
    A =< B, H is A,
    A2 is A + 1, gerar_intervalo(A2, B, T).