#include <stdio.h>

int main(int argc, char *argv[]) {
	int first, second, third;
	int largest;
	if(argc == 4) {
		first = atoi(argv[1]);
		second = atoi(argv[2]);
		third = atoi(argv[3]);
	} else {
		printf("Enter 3 numbers:\n");
		scanf("%d %d %d", &first, &second, &third);
	}
	if(first > second) {
		if(first > third) {
			largest = first;
		} else {
			largest = third;
		}
	} else if(second > third) {
		largest = second;
	} else {
		largest = third;
	}

	printf("Largest is %d\n", largest);

	return 0;
}
