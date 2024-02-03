somaPar([], 0).
somaPar([H | T], R) :-
    somaPar(T, R2),
    ((0 is H mod 2, R is H + R2); R is R2).

