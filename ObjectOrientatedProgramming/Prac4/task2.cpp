#include <iostream>
#include "task2.h"

using namespace std;

void Student::display() {
	cout << "ID: " << studentID << endl;
	cout << "Name: " << studentName << endl;
	cout << "Enrolment Status: " << enrolmentStatus << endl;
	cout << "Course Number: " << courseNo << endl;
}

Student::Student(int stuID, string stuName, bool enrolStat, int courseID) {
	studentID = stuID;
	studentName = stuName;
	enrolmentStatus = enrolStat;
	courseNo = courseID;
}

int main() {

	Student Dib(9, "Josh Dib", true, 1002034);

	Dib.display();
}
