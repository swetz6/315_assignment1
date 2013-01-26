/* 
 * File:   department.h
 * Author: patrick
 *
 * Created on January 22, 2013, 8:56 PM
 */
#include "studentList.h"

#ifndef DEPARTMENT_H
#define	DEPARTMENT_H

class department {
	int departmentID;
	std::string departmentName;
        studentList *departmentList;
public:
	department(int departID, std::string departName)
		:departmentID(departID), departmentName(departName) {
                    departmentList = new studentList();
                }
	int getDepartmentID() {return departmentID;}
	std::string getDepartmentName() {return departmentName;}
        void addStudentToDepartment(student s){departmentList->addStudent(s);}
        void addPayment(feePaymentEntry entry){departmentList->addPayment(entry);}
        void printDepartmentInfo(){
            std::cout << "Department ID: " << getDepartmentID() << 
                    " Department Name: " << getDepartmentName() << '\n';
        }
        void printDepartmentList(){
            std::cout << "Department: " << getDepartmentName() << '\n';
            departmentList->printOutStudents();
        }
       
        //This function is used to check if a particular student is in a 
        //departments list of students already. If the student is in the list,
        //the students index in the list is returned. If they are not in the
        //list, -1 is returned. 
        int studentInDepartment(int studentID){
            int studentInList = departmentList->isStudentID(studentID);
            return studentInList;
        }
        void updateDepartment(student s, feePaymentEntry entry){
            int newStudent = studentInDepartment(s.getStudentID());
            //if -1 signals they are not yet in department
            if (newStudent == -1){
                departmentList->addStudentWithCharge(s, entry);
            }
            //if they are in the department already, newStudent will be the index 
            //of there place in the departmentList. Want to add another entry
            //to the particular students bill then
            else {
                departmentList[newStudent].addPayment(entry);
            }
        }

                    
};
#endif	/* DEPARTMENT_H */

