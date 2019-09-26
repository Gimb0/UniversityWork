#include <stdio.h>

int main() {
	enum week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

	enum week day = Saturday;

	printf("day = %d\n", day+1);
}
