soma([], 0).
soma([H | T], Result) :-
    soma(T, Result2),
    Result is H + Result2.

conta([], 0).
conta([_ | T], Result) :-
    conta(T, Result2),
    Result is 1 + Result2.

media(Lista, Media) :- 
    soma(Lista, Result),
    conta(Lista, Quant),
    Media is Result/Quant,
    !.

verifica_situacao(Media, Situacao) :-
    (
        (Media < 4.0, Situacao = 'Reprovado');
        (Media =< 6.9, Situacao = 'Exame Final');
        (Media > 6.9, Situacao = 'Aprovado')
    ),
    !.