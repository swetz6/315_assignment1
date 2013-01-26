/* 
 * File:   main.cpp
 * Author: patrick
 *
 * Created on January 22, 2013, 8:53 PM
 */

//#include <cstdlib>
//#include "userInterfaceFunctions.h"
#include "userInput.h"


using namespace std;

int main(int argc, char** argv) {
    //create the list of students
    vector<department> listOfDepartments;
    boost::gregorian::date d , dd;
    d = makeDateFromString("1/25/2011");
    dd = makeDateFromString("7/27/2011");
    department cs = createADepartment("1024 Computer Science", listOfDepartments);
    //department is not being added to the department list
    //might be because its by value and not reference
    //cout << "number dep: " << listOfDepartments.size();
    studentList *universityList = new studentList();
    student steve = addNewStudent(14,"steve","glagola","econ",universityList);
    //addAPayment(d,147.15,steve.getStudentID(),universityList);
    //addAPayment(dd,20.00,steve.getStudentID(),universityList);
    addACharge(d,147.25,steve.getStudentID(),"fee",1024,universityList,listOfDepartments);
    //department cs = createADepartment("1024 Computer Science");
    //cs.printDepartmentInfo();
    //printOutDepartmentList(universityList);
    //printStudentStatement(steve.getStudentID(),universityList);
    return 0;
}
/*
//this function creates a new student and adds them to the student list.
student addNewStudent(int id, string firstName, string lastName, string major,studentList *ls){
    student newEnrolee(id,firstName,lastName,major);
    ls->addStudent(newEnrolee);
    return newEnrolee;
}

//addAPayment adds a payment to a students bill
void addAPayment(boost::gregorian::date d, float amount, int studentID,studentList *ls){
    feePaymentEntry newPayment(d,amount,studentID);
    ls->addPayment(newPayment);
}

//addACharge adds either a fee or fine to a students bill
void addACharge(boost::gregorian::date d, float amount, int studentID, string type, int departmentID, studentList *ls){
    feePaymentEntry newPayment(d,amount,studentID,type,departmentID);
    ls->addPayment(newPayment);
}

//findByStudentID is a function that takes a studentID and returns the actual
//student associated with that ID from the list of students.
student findByStudentID(int studentID, studentList *ls){
    student foundStudent = ls->findAStudent(studentID);
    return foundStudent;
}

//given a studentID and a list of students, print out that students statement
void printStudentStatement(int studentID, studentList *ls){
    student studentToPrint = findByStudentID(studentID, ls);
    studentToPrint.printBill();
}

//given a list of students in a department of university, print them out
//along with the total each student owes
void printOutDepartmentList(studentList *ls){
    ls->printOutStudents();
}
 */ 