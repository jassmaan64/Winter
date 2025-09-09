-module(coroner).
-export([loop/0]).

loop() ->
	process_flag(trap_exit, true),
	receive
		{monitor, Process} ->
			link(Process),
			io:format("Monitoring process.\n"),
			loop();

		{'EXIT', From, Reason} ->
			io:format("The shooter \p died with reason \p.",
				[From, Reason]),
				io:format("You should start another.\n"),
			loop()
end.

% 3> Gun = spawn(fun roulette:loop/0).
% <0.97.0>
% 4> Coroner = spawn(fun coroner:loop/0).
% <0.99.0>
% 5> Coroner ! {monitor, Gun).
% * 1:24: syntax error before: ')'
% 5> Coroner ! {monitor, Gun}.
% Monitoring process.
% {monitor,<0.97.0>}
% 6> Gun ! 1.
% click
% 1
% 7> Gun ! 2.
% click
% 2
% 8> Gun !3.
% bang!
% 3
% =ERROR REPORT==== 10-Sep-2023::17:14:06.236025 ===
% Error in process <0.99.0> with exit value:
% {badarg,[{io,format,
%              ["The shooter p died with reason p.",
%               [<0.97.0>,{roulette,die,at,{17,14,6}}]],
%              [{file,"io.erl"},
%               {line,99},
%               {error_info,#{cause => {device,format},
%                             module => erl_stdlib_errors}}]},
%          {coroner,loop,0,[{file,"coroner.erl"},{line,13}]}]}

