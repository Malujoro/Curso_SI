:- op(100, yfx, ++).

[] ++ 0.
[H|T] ++ Result :- 
    T ++ Result2,
    Result is Result2 + H.