/* 
 * File:   userInput.h
 * Author: patrick
 *
 * Created on January 24, 2013, 2:41 PM
 */
#include "userInterfaceFunctions.h"

using namespace std;

string getOperationDesired(string);
void doDesiredOperation(string, studentList*, vector<department> &);
string restOfInput(string);
student createAStudent(string, studentList*);
void addAFee(string, studentList*, vector<department> &);
void processAPayment(string, studentList*);
void printStudentReport(string, studentList*);
department createADepartment(string, vector<department> &);
void addToDepartmentList(department, vector<department> &);
void printDepartmentReport(string, vector<department> &);
void printMajorReport(string, studentList*);
//department departmentFromID(int, vector<department>);











//#ifndef USERINPUT_H
//#define	USERINPUT_H
//#endif	/* USERINPUT_H */

