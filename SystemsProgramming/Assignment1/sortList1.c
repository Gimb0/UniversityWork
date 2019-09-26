#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct iorb {
    int base_pri;			// Base priority.
    struct iorb *link;		// Link to nex node
    char filler[100];		// Data or description of block
} IORB;

struct iorb *HEAD; // Head of linked list

void printList() {
	int count = 0;
	struct iorb *temp = HEAD;
	printf("\nPrinting list\n");
	while((*temp).link != NULL && count < 10) {
		printf("Value: '%s'\t has priority %d\n", (*temp).filler, (*temp).base_pri);
		temp = (*temp).link;
		++count;
	}
	printf("Value: '%s'\t has priority %d\n\n", (*temp).filler, (*temp).base_pri);
}

void sortList(_Bool sort) {
	int size = 1; // Size of list
	struct iorb *temp = HEAD;

	// Get size of list
	while(temp->link != NULL) {
		++size;
		temp = temp->link;
	}


	if(sort) { // Ascending eg. 1, 2, ... , n

		printf("Sorting ascending\n");
		struct iorb *bestPriority;

		// Iterate over list sizeof(list) times
		for(int i = 0; i < size; ++i) {
			printf("Iteration: %d\n", i);

			temp = HEAD;

			// if list is 1,2,4,3,5. index will be 2
			// if list is 2,3,5,1,4. index will be 0
			int index = 0;
			for(int i = 1; i < size + 1; ++i) { // Check current order of list and save index of where it isn't sorted
				if(temp->base_pri == i) {
					++index;
					temp = temp->link;
				} else {
					temp = HEAD;
					break;
				}
			}
			printf("Index is %d\n", index);
			if(index == size) {
				printf("Sorted\n");
				return;
			}

			// Skip over what has already been sorted
			// Temp is the first unsorted element
			for(int j = 0; j < index; ++j) {
				temp = temp->link;
			}
			bestPriority = temp;

			// Finds the best priority
			int indexOfBestPriority, count = index;
			while(temp->link != NULL) {
				if(bestPriority->base_pri > temp->base_pri) {
					bestPriority = temp;
					indexOfBestPriority = count;
				}
				temp = temp->link;
				++count;
			}
			if(bestPriority->base_pri > temp->base_pri) {
				bestPriority = temp;
				indexOfBestPriority = count;
			}

			temp = HEAD;
			// Loop to request block before bestPriority
			for(int j = 0; j != indexOfBestPriority - 1; ++j) {
				temp = temp->link;
			}

			// Set link of request block before bestPriority to request block after bestPriority
			if(bestPriority->link == NULL) {
				temp->link = NULL;
			} else {
				temp->link = bestPriority->link;
			}


			temp = HEAD;
			if(index == 0) {
				bestPriority->link = temp;
				HEAD = bestPriority;
			} else {
				for(int j = 0; j != index - 1; ++j) { // Iterate to before bestPriority sorted position
					temp = temp->link;
				}
				bestPriority->link = temp->link;
				temp->link = bestPriority;
			}
		}
	} else {
		printf("Sorting descending\n");
		struct iorb *bestPriority;

		// Iterate over list sizeof(list) times
		for(int i = 0; i < size; ++i) {
			printf("Iteration: %d\n", i);

			temp = HEAD;

			// if list is 1,2,4,3,5. index will be 2
			// if list is 2,3,5,1,4. index will be 0
			int index = 0;
			for(int i = size; i > 0; --i) { // Check current order of list and save index of where it isn't sorted
				if(temp->base_pri == i) {
					++index;
					temp = temp->link;
				} else {
					temp = HEAD;
					break;
				}
			}
			if(index == size) {
				printf("Sorted\n");
				return;
			}

			// Skip over what has already been sorted
			// Temp is the first unsorted element
			for(int j = 0; j < index; ++j) {
				temp = temp->link;
			}
			bestPriority = temp;

			// Finds the best priority
			int indexOfBestPriority, count = index;
			while(temp->link != NULL) {
				if(bestPriority->base_pri < temp->base_pri) {
					bestPriority = temp;
					indexOfBestPriority = count;
				}
				temp = temp->link;
				++count;
			}
			if(bestPriority->base_pri < temp->base_pri) {
				bestPriority = temp;
				indexOfBestPriority = count;
			}

			temp = HEAD;
			// Loop to request block before bestPriority
			for(int j = 0; j != indexOfBestPriority - 1; ++j) {
				temp = temp->link;
			}

			// Set link of request block before bestPriority to request block after bestPriority
			if(bestPriority->link == NULL) {
				temp->link = NULL;
			} else {
				temp->link = bestPriority->link;
			}


			temp = HEAD;
			if(index == 0) {
				bestPriority->link = temp;
				HEAD = bestPriority;
			} else {
				for(int j = 0; j != index - 1; ++j) { // Iterate to before bestPriority sorted position
					temp = temp->link;
				}
				bestPriority->link = temp->link;
				temp->link = bestPriority;
			}
		}
	}
}

struct iorb* newRequestBlock(int x, char data[100]) {
	struct iorb *newRequestBlock = (struct iorb*)malloc(sizeof(struct iorb));
	(*newRequestBlock).base_pri = x;
	strncpy(newRequestBlock->filler, data, 100);
	newRequestBlock->link = NULL;
	return newRequestBlock;
}

// Add element to front of list
void pushFront(int priority) {
	struct iorb *newRB = newRequestBlock(priority, "Test data cause why not");
	if(HEAD == NULL) {
		HEAD = newRB;
		return;
	} else {
		struct iorb *temp = HEAD;
		newRB->link = temp;
		HEAD = newRB;
	}
	return;
}

void build_list(int limit) {
	srand(time(NULL));

	// Generate array of randomly ordered base_pri
	int possibleNumbers[limit], chosenNumbers[limit];
	for(int i = 0; i < limit; ++i) {
		possibleNumbers[i] = i + 1;
		chosenNumbers[i] = 0;
	}

	int count = 0;
	while(count < limit) {
		_Bool store = 1;
		int index = (rand() % limit);
		for(int j = 0; j < count + 1; ++j) {
			if(possibleNumbers[index] == chosenNumbers[j]) {
				store = 0;
				break;
			}
		}
		if(store) {
			chosenNumbers[count] = possibleNumbers[index];
			count++;
		}
	}

	int i = 0;
	while(i < limit) {
		pushFront(chosenNumbers[i]);
		++i;
	}
}
