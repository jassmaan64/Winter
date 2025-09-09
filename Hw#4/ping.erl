-module(ping).
-export([loop/0]).

% loop() ->
% 	receive
% 		hello -> io:format("hello back\n"),
% 			loop();
% 		_     -> io:format("I did not understand\n"),
% 			loop()
% end.
% tail recursion as recursive call replaces the recursive call as goes on and on
% if tail recursion is not called you keep calling and stack would fill up

% 2> P = spawn(fun helloworld:loop/0).
% <0.92.0>
% 3> P
% .. .
% <0.92.0>
% 4> P ! hello.
% hello back
% hello
% 5> P ! hi.
% I did not understand
% hi

loop()	->
		receive
			{start, Process}	-> io:format("starting\n"),
									io:format("sending ping\n"),
									Process ! {ping, self(), 1},
									loop();
			{pong, Process, N}	-> io:format("sending ping \p\n", [N + 1]),
									Process ! {ping, self(), N + 1},
									loop();
			_ 					-> io:format("huh?\n"),
									loop()
end.