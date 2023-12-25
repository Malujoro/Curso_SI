hit(shape_of_You, ed_sheeran).
hit(thinking_Out_Loud, ed_sheeran).
hit(blinding_Lights, the_weeknd).
hit(uptown_Funk, bruno_mars).
hit(happy, pharrell_williams).
hit(love_yourself, justin_bieber).
hit(closer, the_chainsmokers).
hit(dont_Stop_Believing, journey).
hit(cheap_Thrills, sia).
hit(rolling_in_the_Deep, adele).

artista_com_hits(X) :-
    hit(H1, X), hit(H2, X), H1 \= H2.