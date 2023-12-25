soma([], 0).
soma([H | T], Result) :-
    soma(T, Result2),
    Result is H + Result2.

media(Lista, Media) :- 
    soma(Lista, Result),
    Media is Result/4,
    !.

verifica_situacao(Media, Situacao) :-
    (
        (Media < 4.0, Situacao = "Reprovado");
        (Media =< 6.9, Situacao = "Exame Final");
        (Media > 6.9, Situacao = "Aprovado")
    ),
    !.