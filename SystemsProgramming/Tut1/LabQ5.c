#include <stdio.h>

int largest(int a, int b, int c) {	
	int largest;
	if(a > b) {
		if(a > c) {
			largest = a;
		} else {
			largest = c;
		}
	} else if(b > c) {
		largest = b;
	} else {
		largest = c;
	}
	return largest;
}

int main(int argc, char *argv[]) {
	int first, second, third;
	if(argc == 4) {
		first = atoi(argv[1]);
		second = atoi(argv[2]);
		third = atoi(argv[3]);
	} else {
		printf("Enter 3 numbers:\n");
		scanf("%d %d %d", &first, &second, &third);
	}

	printf("Largest is %d\n", largest(first, second, third));

	return 0;
}
