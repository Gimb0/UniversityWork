active proctype P() {
	int dividend = 16;
	int divisor = 4;
	int quotient, remainder;

	assert(dividend >= divisor && divisor > 0);

	quotient = 0;
	remainder = dividend;

	do
	:: remainder > divisor -> quotient++;
	   remainder = remainder - divisor;
	:: else -> break
	od;

	printf("%d / %d = %d, remainder = %d\n",
		    dividend, divisor, quotient, remainder);

	assert(0 <= remainder && remainder < divisor);
	assert(dividend == quotient * divisor + remainder);
}
