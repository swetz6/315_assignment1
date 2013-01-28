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
    else if(operation.compare("PD")==0){
        printDepartmentReport(remainingInstructions, ds);
    }
    else if(operation.compare("PM")==0){
        printMajorReport(remainingInstructions, ls);
    }
    else {
        cout << "Invalid Command, please make sure to capitalize the command.";
    }
        
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
    string type, date, stuID, depID, amt;
    istringstream is(input);
    getline(is, stuID, ' ');
    getline(is, depID, ' ');
    getline(is, amt, ' ');
    getline(is, date, ' ');
    getline(is, type, '\n');
    studentID = makeIntFromString(stuID);
    departmentID = makeIntFromString(depID);
    amount = makeFloatFromString(amt);
    //is >> studentID >> departmentID >> amount >> date >> type;
    d = makeDateFromString(date);
    //cout << "Is it a float? " << amount; 
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

void printDepartmentReport(string input, vector<department> &ds){
    int departmentID;
    istringstream is(input);
    is >> departmentID;
    department depToPrint = departmentFromID(departmentID, ds);
    depToPrint.printDepartmentList();
}

void printMajorReport(string input, studentList* ls){
    string major;
    vector<student> studentsInMajor;
    istringstream is(input);
    is >> major;
    ls->studentsInMajor(major, studentsInMajor);
    cout << "Students in the " << major << " major" << '\n';
    for (int i = 0; i < studentsInMajor.size(); i++){
        studentsInMajor[i].printBill();
    }
}