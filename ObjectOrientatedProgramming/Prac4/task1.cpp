//Searches a partially filled array of nonnegative integers.
#include <iostream>
#include "task1.h"

using namespace std;

void makeAndSearchArray::fillArray() {
    cout << "Enter up to " << DECLARED_SIZE << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < DECLARED_SIZE))
    {
        arr[index] = next;
        index++;
        cin >> next;
    }

    listSize = index;
}

int makeAndSearchArray::search(int target) {
    int index = 0;
    bool found = false;
    while ((!found) && (index < listSize))
    if (target == arr[index])
        found = true;
    else
        index++;

    if (found)
        return index;
    else
        return -1;
}

int main() {

	makeAndSearchArray array1;

    array1.fillArray();

    char ans;
    int result, target;
    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        result = array1.search(target);
        if(result == -1)
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position "
                 << result << endl
                 << "(Remember: The first position is 0.)\n";

        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}
