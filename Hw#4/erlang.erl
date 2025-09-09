
-module(mylist)
-export([mycount/2])

mycount([],_) -> 0;
mycount([H|T], V)when H ++ V-> 1+ mycount(T, V);
mycount([_|T], V)-> mycount(T, V).

