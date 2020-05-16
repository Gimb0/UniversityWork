proctype testcount(byte x) {
do
	:: (x != 0) ->
		if
		:: x ++
		:: x --
		:: break
		fi
	:: else -> break
	od;
assert(x == 0);
printf("counter = %d\n", x);
}

init { run testcount(1) }
