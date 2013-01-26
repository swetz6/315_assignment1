/* 
 * File:   feePaymentEntry.h
 * Author: patrick
 *
 * Created on January 22, 2013, 10:29 PM
 */
//gregorian.hpp is the boost library for date
#include "../boost/date_time/gregorian/gregorian.hpp"
#include <string>

//This class is designed to produce the individual fines, payments, and fees
//to go onto a student bill. The fields are: a date field that the specific charge
//was added. An amount field that specifies the actual amount of the entry.
//a student ID field to identify the student who's bill the entry is to be assigned.
//A type field to specify if the entry is a fee, fine, or payment. And finally,
//a department ID field to identify the department who put the charge or payment
//on a student's bill.

#ifndef FEEPAYMENTENTRY_H
#define	FEEPAYMENTENTRY_H

class feePaymentEntry {
    boost::gregorian::date d;
    float amount;
    int studentID;
    std::string type;
    int departmentID;
public:
    boost::gregorian::date getDate() {return d;}
    float getAmount() {return amount;}
    int getStudentID() {return studentID;}
    std::string getType() {return type;}
    int getDepartmentID() {return departmentID;}
    
    //The constructor for a payment entry. The department ID will always be 00000
    //to identify a payment. 
    feePaymentEntry(boost::gregorian::date e, float amt, int student)
            :d(e), amount(amt), studentID(student) {
                departmentID=00000;
                type="payment";
    }
    
    //The constructor for a fee/fine entry. 
    feePaymentEntry(boost::gregorian::date e, float amt, int student, std::string fineType, int depID)
            :d(e), amount(-amt), studentID(student), type(fineType), departmentID(depID) {}
};



#endif	/* FEEPAYMENTENTRY_H */

