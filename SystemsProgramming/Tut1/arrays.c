#include <stdio.h>

#define row 10
#define col 10
#define size (row) * (col)

int main() {
	int arr[row][col], p;
	for(p=0; p<size; p++) {
		(*arr)[p] = p;
		printf("%p\n", &(*arr)[p]);
	}	
	
	/*
	//Prints out array	
	printf("Array conatins:\n");
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}
