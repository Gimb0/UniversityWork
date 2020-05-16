#include <string>

using namespace std;

class Student {
	int studentID, courseNo;
	string studentName;
	bool enrolmentStatus;


public:
	void display();
	Student(int stuID, string stuName, bool enrolStat, int courseID);
};
