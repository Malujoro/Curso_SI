:- op(100, yfx, ++).

% Operador para calcular e exibir a soma entre dois quadrados
X ++ Y :- R is (X*X + Y*Y), write(R).

% "Regra" para calcular e retornar a soma entre dois quadrados
++(X, Y, R) :- R is (X*X + Y*Y).