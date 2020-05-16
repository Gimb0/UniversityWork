#include "sortList.c"

// Function declarations
void build_list(int limit);
struct iorb* newRequestBlock(int x, char data[100]);
void pushFront(int priority, char *line);
void printList();
void sortList(_Bool sort);

int main() {
	HEAD = NULL;
	build_list(5);

	printList();

	sortList(1);

	printList();
}
