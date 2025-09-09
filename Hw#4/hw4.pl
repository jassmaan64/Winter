
shuffle([], [], []).
shuffle(([H1|T1]), [H2|T2], [H1, H2|T3]):- shuffle(T1, T2, T3).

double([], []).
double([H1|T1], [H1, H1|T2]):- double(T1, T2).


remove_all(_, [], []).
remove_all(X, [X|T], R) :- remove_all(X, T, R).
remove_all(X, [H|T], [H|R]) :- X \= H, remove_all(X, T, R).

no_duplicates([], []).
no_duplicates([H|T], L2):- member(H, T), no_duplicates(T, L2).
no_duplicates([H|T], [H|L2]):- \+ member(H, T), no_duplicates(T, L2).

# same_elements(L1, L2) :-
#     length(L1, N),
#     length(L2, N),
#     all_elements_in_list(L1, L2),
#     all_elements_in_list(L2, L1).

# all_elements_in_list([], _).
# all_elements_in_list([H|T], List) :-
#     member(H, List),
#     all_elements_in_list(T, List).

same_elements(L1, L2) :-
    length(L1, N),
    length(L2, N),
    forall((member(E, L1), count_occurrences(E, L1, Count1)), count_occurrences(E, L2, Count1)).

count_occurrences(_, [], 0).
count_occurrences(E, [E|T], N) :-
    count_occurrences(E, T, N1),
    N is N1 + 1.
count_occurrences(E, [H|T], N) :-
    E \= H,
    count_occurrences(E, T, N).