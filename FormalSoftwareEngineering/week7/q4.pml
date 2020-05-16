byte in;
byte x,y,z;
active [2] proctype user() { 
  byte me = _pid+1; 
  L1: x = me;
  L2: if
	:: (y != 0 && y != me) -> goto L1
	:: (y == 0 || y == me)
	fi;
  L3: z = me;
  L4: if
	:: (x != me) -> goto L1
	:: (x == me)
	fi;
  L5: y = me;
  L6: if
	:: (z != me) -> goto L1
	:: (z == me)
	fi;
  L7:
	in = in+1;
	assert(in==1);
	in = in - 1;
	goto L1
}
