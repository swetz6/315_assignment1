#include "userInterfaceFunctions.h"



//this function creates a new student and adds them to the student list.
student addNewStudent(int id, string firstName, string lastName, string major,studentList *ls){
    student newEnrolee(id, firstName, lastName, major);
    ls->addStudent(newEnrolee);
    return newEnrolee;
}

//addAPayment adds a payment to a students bill
void addAPayment(boost::gregorian::date d, float amount, int studentID, studentList *ls){
    feePaymentEntry newPayment(d, amount, studentID);
    ls->addPayment(newPayment);
}

//addACharge adds either a fee or fine to a students bill
void addACharge(boost::gregorian::date d, float amount, int studentID, string type, int departmentID, studentList *ls, vector<department> &ds){
    feePaymentEntry newPayment(d, amount, studentID, type, departmentID);
    ls->addPayment(newPayment);
    department depToUpdate = departmentFromID(departmentID, ds);
    //depToUpdate.printDepartmentInfo();
    student studentToAdd = findByStudentID(studentID, ls);
    depToUpdate.updateDepartment(studentToAdd, newPayment);
    depToUpdate.printDepartmentList();
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
    cout << studentToPrint.getFirstName() << " " << 
            studentToPrint.getLastName() << " " << 
            studentToPrint.getMajor() << '\n';
    studentToPrint.printBill();
}

//given a list of students in a department of university, print them out
//along with the total each student owes
void printOutDepartmentList(studentList *ls){
    ls->printOutStudents();
}

//This is a helper function to the makeDateFromString function. This function
//named makeDate, takes in three ints representing the month, 
//day of the week, and year. It converts them to the proper boost::gregorian
//format and returns a gregorian date.
boost::gregorian::date makeDate(int month, int day, int year){
    boost::gregorian::greg_year yr(year);
    boost::gregorian::greg_month m(month);
    boost::gregorian::greg_day d(day);
    boost::gregorian::date returnDate(yr,m,d);
    return returnDate;
}

//this a helper function to makeDateFromString. This function takes in a string
//representing either the day, month, or year. It then converts that string to an
//int so that the makeDate function can use the numbers. 
int makeIntFromString(string s){
    int returnValue;
    istringstream is(s);
    is >> returnValue;
    return returnValue;
}

//function takes in a string representing a date in the form DD/MM/YYYY
//it returns a date represented by the boost class gregorian date
boost::gregorian::date makeDateFromString(string s){
    int day, month, year;
    string d, m, y;
    istringstream is(s);
    getline(is,m,'/');
    getline(is,d,'/');
    getline(is,y);
    day = makeIntFromString(d);
    month = makeIntFromString(m);
    year = makeIntFromString(y);
    boost::gregorian::date newDate(makeDate(month,day,year));
    return newDate;
}

//***** NEED TO FIX *****
department departmentFromID(int departmentID, vector<department> ds){
    for(int i = 0; i<ds.size(); i++){
        if(departmentID == ds[i].getDepartmentID()){
            return ds[i];
        }
    }
}


