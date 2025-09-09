-module(hw5).
-export([myremoveduplicates/1, myintersection/2, mylast/1, myreverse/1, myreplaceall/3]).

%prob 1
myremoveduplicates([]) -> [];
myremoveduplicates([H|T]) -> remove_duplicates([H|T], []).

remove_duplicates([], Acc) -> lists:reverse(Acc);
remove_duplicates([H|T], Acc) ->
    case lists:member(H, T) of
        true -> remove_duplicates(T, Acc);
        false -> remove_duplicates(T, [H|Acc])
    end.
%remove_duplicates([H|T], Acc) ->
%    case is_element_of(H, Acc) of
%        true -> remove_duplicates(T, Acc);
%        false -> remove_duplicates(T, [H|Acc])
%    end.

is_element_of(_, []) -> false;
is_element_of(X, [X|_]) -> true;
is_element_of(X, [_|T]) -> is_element_of(X, T).

%prob2
myintersection(_,[]) -> [];
myintersection([],_) -> [];
myintersection([H1|T1],[H2|T2]) -> intersection([H1|T1],[H2|T2], []).

% intersection([_],[], Acc) -> lists:reverse(Acc);
intersection([],_, Acc) -> lists:reverse(Acc);
intersection([H1|T1],[H2|T2], Acc) ->
    case is_element_of(H1,[H2|T2]) of
        true -> intersection(T1, [H2|T2], [H1|Acc]);
        false -> intersection(T1, [H2|T2], Acc)
    end.

mylast([""]) -> [""];
mylast([]) -> [];
mylast([X]) -> [X];
mylast([_|T1])-> mylast(T1).
%mylast([H1|T1]) -> last([H1|T1], []).


%prob4
myreverse([]) -> [];
myreverse([X]) -> [X];
myreverse([H|T]) -> reversed([H|T], []).

reversed([], Acc) -> Acc;
reversed([X], Acc) -> [X|Acc];
reversed([H|T], Acc) -> reversed(T, [H|Acc]).

myreplaceall(_,_,[]) -> [];
myreplaceall(X,Y,[H|T]) -> replaceall(X,Y,[H|T], []).

replaceall(_,_,[],Acc) -> lists:reverse(Acc);
replaceall(X,Y,[Y|T],Acc) -> replaceall(X,Y,T,[X|Acc]);
replaceall(X,Y,[H|T],Acc) -> replaceall(X,Y,T,[H|Acc]).