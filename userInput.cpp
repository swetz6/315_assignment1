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
    getline(is, throwAwayInstruction, ' ');
    getline(is, remainingInstructions);
    return remainingInstructions;
}

void doDesiredOperation(string s, studentList *ls, vector<department> &ds){
    string operation = getOperationDesired(s);
    string remainingInstructions = restOfInput(s);
    if (operation.compare("S")==0){
        createAStudent(remainingInstructions, ls);
    }
    else if(operation.compare("D")==0){
        department newDepartment = createADepartment(remainingInstructions, ds);
        //addToDepartmentList(newDepartment, ds);
    }
    else if(operation.compare("F")==0){
        addAFee(remainingInstructions, ls, ds);
    }
    else if(operation.compare("P")==0){
        processAPayment(remainingInstructions, ls);
    }
    else if(operation.compare("PS")==0){
        printStudentReport(remainingInstructions, ls);
    }
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

void addAFee(string input, studentList* ls, vector<department> &ds){
    int studentID,departmentID;
    float amount;
    boost::gregorian::date d;
    string type, date;
    istringstream is(input);
    is >> studentID >> departmentID >> amount >> date >> type;
    d = makeDateFromString(date);
    addACharge(d, amount, studentID, type, departmentID, ls, ds);
    return;
}

void processAPayment(string input, studentList *ls){
    int studentID;
    float amount;
    boost::gregorian::date d;
    string stringDate;
    istringstream is(input);
    is >> studentID >> amount >> stringDate;
    d = makeDateFromString(stringDate);
    addAPayment(d, amount, studentID, ls);
    return;
}

void printStudentReport(string input, studentList *ls){
    int studentID;
    istringstream is(input);
    is >> studentID;
    printStudentStatement(studentID, ls);
    return;
}

//*****change to taking in a vector also and pushing the department to the vector 
department createADepartment(string input, vector<department> &ds){
    int departmentID;
    string departmentName, stringID;
    istringstream is(input);
    getline(is, stringID, ' ');
    getline(is, departmentName);
    departmentID = makeIntFromString(stringID);
    department newDepartment(departmentID, departmentName);
    addToDepartmentList(newDepartment, ds);
    return newDepartment;
}

void addToDepartmentList(department d, vector<department> &ds){
    ds.push_back(d);
}

//Takes a departmentID and the list of all departments and returns
//the department associated with the ID
/*department departmentFromID(int departmentID, vector<department> ds){
    for(int i = 0; i<ds.size(); i++){
        if(departmentID == ds[i].getDepartmentID()){
            return ds[i];
        }
    }
}*/
