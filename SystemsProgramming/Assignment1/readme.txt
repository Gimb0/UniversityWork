Bradley Semlitzky - Student Number: 19033567

1
Linux instructions
Compiling code:
1. gcc main.c
Running code:
1. ./a.out

2
Program logic
Build List:
	Create array of 1-5
	a. Create random number between 0-4 for index
	b. Get number in array at randomly generated index
	c. If this number is not in another array, store it else a).

	Open file with data for filler variable
	Read line of Data
	Loop through array of randomly ordered numbers and pass it and line of data to pushFront Function
	Close file

pushFront:
	Creates a pointer to a iorb created on the heap
	The new iorb holds the priority and data passed to pushFront function
	Place the new iorb at the start of the linked List

sortList:
	Only requirement is that it is passed a boolean for how to sort the List
	Finds the size of the list by iterating through till the end
	Loop to run n times (n being size of the list)

	Ascending:
		Loop through the list again to see how much of it is sorted
		Using check of how much is sorted move index to first unsorted request block
		Pointer to best request block points to first unsorted element
