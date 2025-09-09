% -module(erltest).
% -export([double/1, mylength/1, mysum/1, repeat/1, mymap/2]).

% double(Number) -> 2 * Number.

% mylength([]) -> 0;
% mylength([_|T]) -> 1 + mylength(T).

% mysum([])   -> 0;
% mysum([H|T])    -> H + mysum(T).

% % case Animal of 
% % .. "dog" -> goodpet;
% % .. "cat" -> badpet
% % .. end.
% % goodpet

% % 10> X = 0.
% % 0
% % 11> if
% %  .. X > 0 -> positive;
% %  .. X < 0 -> negative
% %  .. end.
% % ** exception error: no true branch found when evaluating an if expression
% % 12> if
% %  .. X > 0 -> positive;
% %  .. X < 0 -> negative;
% %  .. true -> zero
% %  .. end.
% % zero
% % 13> if
% %  .. X >= 0 -> positive;
% %  .. X < 0 -> negative
% %  .. end.
% % positive

% % 15> [1 | []].
% % [1]
% % 16> [2 | [1 | []]].
% % [2,1]
% % 17> [[] | [1,2]].
% % [[],1,2]

% repeat([]) -> [];
% repeat([H|T]) -> [H | [H| repeat(T)]].

%             % Anonymus/lamda function
% % 21> Square = fun(N)                -> N * N end.
% % 24> Numbers = [1,2,3,4].
% % [1,2,3,4]
% % 25> lists:map(Square, Numbers).
% % [1,4,9,16]
% % 26> lists:map(fun(N) -> N*N end, Numbers).
% % [1,4,9,16]

% mymap(F,[]) -> [];
% mymap(F, [H|T]) -> [F(H) | mymap(F, T)].
% % 28> erltest:mymap(Square, Numbers).
% % [1,4,9,16]

% % 29> LT3 = fun(X) -> X < 3 end.
% % #Fun<erl_eval.42.125776118>
% % 30> lists:filter(LT3, Numbers).
% % [1,2]

% % lists:foldl(fun(X,Sum) -> X +Sum end, 0, Numbers).
% % 10

% % lists:foldl(fun(X,Product) -> X * Product end, 1, Numbers).
% % 24

% % 34> [Square(X) || X <- Numbers].
% % [1,4,9,16]

% % 35> [X * X || X <- [1,2,3,4]].
% % [1,4,9,16]

% % spawn - sends a concurrent process
% % send - sends messsage to a process
% % receive - receives a message sent from another process

% % <Pid> = spawn(<Fun>).
% % P = spawn(fun helloworld:loop/0).

% % send operator
% % <Pid>!<Message>
% % P!hello.

% % receive operator
% % received
% % <Pattern1><Guard1> ->
% %   <Expression1>;
% % <Pattern2><Guard2> ->
% %   <Expression2>;
% % --
% %end.

-module(roulette).
-export([loop/0]).

%expect a number from 1 to 6
loop() ->
    receive
        3 -> io:format("bang!\n"),
        exit({roulette,die,at,erlang:time()});
        _ -> io:format("click\n"), loop()
end.

% 2> Gun = spawn(fun roulette:loop/0).
% <0.92.0>
% 3> Gun ! 1.
% click
% 1
% 4> Gun ! 2.
% click
% 2
% 5> Gun ! 3.
% bang!  This is where the process dies
% 3
% 6> Gun ! 4.
% 4     That is why no click or bang
% 7> erlang:is_process_alive(Gun).
% false
