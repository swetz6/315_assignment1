/* 
 * File:   userInterfaceFunctions.h
 * Author: patrick
 *
 * Created on January 24, 2013, 1:12 PM
 */
#include "department.h"
#include "studentList.h"
#include <sstream>
#include <cstdlib>

using namespace std;

student addNewStudent(int,string,string,string,studentList*);
void addAPayment(boost::gregorian::date,float,int,studentList*);
void addACharge(boost::gregorian::date,float,int,string,int,studentList*);
student findByStudentID(int studentID, studentList*);
void printStudentStatement(int studentID, studentList*);
void printOutDepartmentList(studentList*); 
boost::gregorian::date makeDate(int,int,int);
boost::gregorian::date makeDateFromString(string);
int makeIntFromString(string);

//#ifndef USERINTERFACEFUNCTIONS_H
//#define	USERINTERFACEFUNCTIONS_H
//#endif	/* USERINTERFACEFUNCTIONS_H */

