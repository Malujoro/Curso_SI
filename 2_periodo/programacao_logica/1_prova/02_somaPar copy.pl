somaLista([], 0).

somaLista([H | T], Soma) :-  
    somaLista(T, Soma2), 
    ((0 is H mod 2) -> Soma is Soma2 + H ; Soma = Soma2). 


intervalo(X, Y, [X]) :- X is Y.
intervalo(X, Y, [X|T]) :- X < Y,
    X2 is X + 1,
    intervalo(X2, Y, T).