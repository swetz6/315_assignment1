/* 
 * File:   student.h
 * Author: patrick
 *
 * Created on January 22, 2013, 8:55 PM
 */
//class student is used to represent individual students. It has 5 fields: 
//a studentID field, a field for the first name, one for the last name, 
//a field for the college major and finally a field that represents the 
//fees, fines, and payments a student has made at the university
//This "bill" field is represented by a vector of fees and payments.

#include <vector>
#include "feePaymentEntry.h"

#ifndef STUDENT_H
#define	STUDENT_H

class student {
	int studentID;
	std::string firstName;
	std::string lastName;
	std::string collegeMajor;
        std::vector<feePaymentEntry> studentBill;
        
public:
        //constructor to define a new student
	student(int stdID, std::string firstN, std::string lastN, std::string mj)
		:studentID(stdID),firstName(firstN),lastName(lastN),collegeMajor(mj) {
                    studentBill = std::vector<feePaymentEntry>();
                }
	student();
        
        boost::gregorian::date firstEntryDate() {return studentBill[0].getDate();}
        
        //get a students id number
	int getStudentID(){return studentID;}
        
        //get a students first name
	std::string getFirstName(){return firstName;}
        
        //get a students last name
	std::string getLastName(){return lastName;}
        
        //get a students major
	std::string getMajor(){return collegeMajor;}
        
        //add a new payment/fee entry to a student's bill
        void addEntry(feePaymentEntry entry){studentBill.push_back(entry);}
        
        //getTotal finds the total of the billing statement of a particular student
        float getTotal();
        
        //printBill prints the fees and payments of a particular student
        void printBill();
        
        int numberEntries(){return studentBill.size();}
        float calcAttempt();
        bool entryInMonth(feePaymentEntry, boost::gregorian::date);
        boost::gregorian::date startOfNextMonth(boost::gregorian::date);
};

#endif	/* STUDENT_H */

