#include "userInput.h"

string getOperationDesired(string s){
    string operation;
    istringstream is(s);
    getline(is,operation, ' ');
    return operation;
}

string restOfInput(string s){
    string remainingInstructions, throwAwayInstruction;
    istringstream is(s);
    getline(is,throwAwayInstruction,' ');
    getline(is,remainingInstructions);
    return remainingInstructions;
}

void doDesiredOperation(string s, studentList *ls){
    string operation = getOperationDesired(s);
    if (operation.compare("S")==0)//call create a student (3 args)
        return;
    else if(operation.compare("D")==0)//call create a dept (2 args)
        return;
    else if(operation.compare("F")==0)//create a fine (5 args)
        return;
    else if(operation.compare("P")==0)//create a payment(3 args)
        return;
    else if(operation.compare("PS")==0)//print report based on studentID
        return;
    else if(operation.compare("PD")==0)//print report for department
        return;
    else if(operation.compare("PM")==0)//print a major report
        return;
    else 
        return;
}

//this function will return a student when the user enters an 'S' as the operation desired
//the student will be created based on the rest of the input from the user.
student createAStudent(string studentInfo, studentList *ls){
    int studentID;
    string firstName, lastName, major;
    istringstream is(studentInfo);
    is >> studentID >> firstName >> lastName >> major;
    student newStudent = addNewStudent(studentID, firstName, lastName, major, ls);
    return newStudent;
}

void addAFee(string input, studentList* ls){
    int studentID,departmentID;
    float amount;
    boost::gregorian::date d;
    string type, date;
    istringstream is(input);
    is >> studentID >> departmentID >> amount >> date >> type;
    d = makeDateFromString(date);
    addACharge(d,amount,studentID,type,departmentID,ls);
    return;
}
