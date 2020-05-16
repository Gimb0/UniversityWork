#include <iostream>

using namespace std;

void testDefaultArg(int day = 1, string month= "Jan",
                    int year = 2017) {
     cout << "Today is " << day <<" "
     << month << " " << year << endl;
}

int main() {
    testDefaultArg();
    testDefaultArg(7);
    testDefaultArg(7, "Dec");
    testDefaultArg(7, "Dec", 1998);

    return 0;
}
