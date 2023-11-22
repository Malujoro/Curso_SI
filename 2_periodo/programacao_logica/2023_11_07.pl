pai(ivo, eva).
pai(gil, rai).
pai(gil, clo).
pai(gil, ary).
pai(rai, noe).
pai(ary, gal).

mae(ana, eva).
mae(bia, rai).
mae(bia, clo).
mae(bia, ary).
mae(eva, noe).
mae(lia, gal).

irmao(X, Y) :- 
    pai(Z, X), mae(W, X),
    pai(Z, Y), mae(W, Y),
    X \= Y.