#include "studentList.h"

bool studentList::isStudent(std::string lastName){
        for(int i=0;i<listOfStudents.size();i++){
            std::string nameToCompare = listOfStudents[i].getLastName();
            if(lastName.compare(nameToCompare)==0) return true;
        }
        return false;
}
    
    //this function is for using a studentID number to properly identify the student
    //in the list of students. We return the index of the location of the student
    //in the vector of students.

int studentList::isStudentID(int idNum){
        for(int i=0;i<listOfStudents.size();i++){
            int numToCompare = listOfStudents[i].getStudentID();
            if(numToCompare==idNum) return i;
        }
        return -1;
 }
    
    //addPayment is used to add a fee or payment to a particular student in the list
void studentList::addPayment(feePaymentEntry entry){
        int studentIndex = isStudentID(entry.getStudentID());
        listOfStudents[studentIndex].addEntry(entry);
}
    
    //given a student ID, return the student associated with the ID
student studentList::findAStudent(int studentID){
        int studentIndex = isStudentID(studentID);
        return (listOfStudents[studentIndex]);
} 
    
void studentList::printOutStudents(){
        for(int i=0;i<listOfStudents.size(); i++){
            std::cout << "student last name: " << listOfStudents[i].getLastName();
            std::cout << '\t' << "student owes: " << listOfStudents[i].getTotal() << '\n';
        }
}

void studentList::printOutATotal(int studentID){
    student toPrint = findAStudent(studentID);
}

