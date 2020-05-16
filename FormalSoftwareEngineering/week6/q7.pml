#define mutex !(critical == 1 && formalSW == true)
#define liveness (P@cs || Q@cs)

byte critical = 1;
bool formalSW = false;
active proctype P() {
	do
		:: printf("Noncritical section P\n");
		   critical == 1;
		   cs: printf("Critical section P\n");
		   critical = 2;
	od
}

active proctype Q() {
	do
		:: printf("Noncritical section Q\n");
		   critical == 2;
		   formalSW = true;
		   cs: printf("Critical section Q\n");
		   formalSW = false;
		   critical = 1;
	od
}
