#define liveness (P@cs || Q@cs)

bool wantP=false, wantQ=false;
byte last=0;

active proctype P() {
  do
	:: if
	  :: true
	  :: true -> false
	fi;
	wantP=true;
	try: (wantQ==false) || (last==2);
	cs: wantP=false;
	last=1
  od
}

active proctype Q() {
  do
	:: wantQ=true;
	try: (wantP == false) || (last==1);
	cs: wantQ=false;
	last=2
  od
}
