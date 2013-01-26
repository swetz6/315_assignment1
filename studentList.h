/* 
 * File:   studentList.h
 * Author: patrick
 *
 * Created on January 23, 2013, 12:25 AM
 */

#include "student.h"

#ifndef STUDENTLIST_H
#define	STUDENTLIST_H

//The studentList class is used to hold a list of all students at the school.
//It has one field, a vector of all students. Upon creation of a new student,
//they are automatically added to the end of the list. 

class studentList{
    std::vector<student> listOfStudents;
public:
    studentList(){
    listOfStudents = std::vector<student>();
}
    //addStudent takes a student and adds them to the list of students.
    void addStudent(student newStudent) {listOfStudents.push_back(newStudent);}
    //isStudent determines by last name if a person is a student or not
    bool isStudent(std::string lastName);
    
    //this function is for using a studentID number to properly identify the student
    //in the list of students. We return the index of the location of the student
    //in the vector of students.
    int isStudentID(int idNum);
    
    //addPayment is used to add a fee or payment to a particular student in the list
    void addPayment(feePaymentEntry entry);
    
    //given a student ID, return the student associated with the ID
    student findAStudent(int studentID);
    
    void printOutStudents();
    void printOutATotal(int studentID);
    void addStudentWithCharge(student newStudent, feePaymentEntry entry);
    
    
};

#endif	/* STUDENTLIST_H */

