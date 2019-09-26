# include <stdio.h>
/*print Fahrenheit-Celsius table for fah=0,20..,200*/

int main() {
	int fah, cel;
	int lower, upper, step;
	lower=0;  /*lower limit of the temperature table */
	upper=400;  /* upper limit */
	step=20;  /*step size */
	fah = lower;
	do {
		cel=5*(fah-32)/9;
		printf("%d\t%d\n", fah, cel);
		fah+=step;
	} while(fah<=upper);
}
