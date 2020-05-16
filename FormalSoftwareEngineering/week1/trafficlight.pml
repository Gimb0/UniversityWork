mtype = {red, yellow, green};
mytpe light = green;

active proctype P() {
	do
		:: if
			:: light == red -> light == green
			:: light == yellow -> light == red
			:: light == green -> light == yellow
		fi;
		printf("the light is now %e\n", light)
	od
}
