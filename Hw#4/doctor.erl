-module(doctor).
-export([loop/0]).

% loop() ->
% 	process_flag(trap_exit, true),
% 	receive
% 		new -> 
% 			io:format("Creating and monitoring process.\n"),
% 			register(gun, spawn_link(fun roulette:loop/0)),
% 			loop();

% 		{'EXIT', From, Reason} ->
% 			io:format("The shooter \p died with reason \p.",
% 				[From, Reason]),
% 				io:format("Restarting.\n"),
% 			self() ! new,
% 			loop()
% end.

loop() ->
    process_flag(trap_exit, true),
    receive
        new -> 
            io:format("Creating and monitoring process.\n"),
            register(gun, spawn_link(fun roulette:loop/0)),
            loop();

        {'EXIT', From, Reason} ->
            io:format("The shooter ~p died with reason ~p.~n",
                [From, Reason]),
            io:format("Restarting.~n"),
            self() ! new,
            loop()
    end.

% 12> c(doctor).
% {ok,doctor}
% 13> Doc = spawn(fun doctor:loop/0).
% ** exception error: no match of right hand side value <0.122.0>
% 14> c(doctor).
% {ok,doctor}
% 15> Doc = spawn(fun doctor:loop/0).
% ** exception error: no match of right hand side value <0.130.0>
% 16> Doc1 = spawn(fun doctor:loop/0).
% <0.133.0>
% 17> Doc ! new.
% new
% 18> Doc1 ! new.
% Creating and monitoring process.
% new
% 19> gun ! 1.
% click
% 1
% 20> gun ! 3.
% bang!
% 3
% The shooter <0.136.0> died with reason {roulette,die,at,{17,36,8}}.
% Restarting.
% Creating and monitoring process.