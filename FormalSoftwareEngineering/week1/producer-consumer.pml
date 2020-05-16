mtype = {P,C};
mtype turn = P;

active proctype produce()
{ do
	:: (turn == P || turn == C) ->
		printf("Produce.\n");
		turn = C;
	od
}

active proctype consume()
{ do
	:: (turn == C) ->
		printf("Consume.\n");
		turn = P;
	od
}
