#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	if(n == 0){
		return 0;
	} else if(n == 1) {
		return 1;
	} else {
		return (fib(n-1) + fib(n-2));
	}
}

int main(int argc, char *argv[]) {
	int n = 0;
	if(argc != 2) {
		printf("Enter n: ");
		while(n < 2) {
			scanf("%d", &n);
		}	
	} else {
		n = atoi(argv[1]);
	}

	int fibNum = fib(n);

	printf("The %dth fibonacci number is %d\n", n, fibNum);

	return 1;
}

