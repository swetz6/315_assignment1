/* 
 * File:   main.cpp
 * Author: patrick
 *
 * Created on January 22, 2013, 8:53 PM
 */

#include "userInput.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    //create the list of students
    vector<department> listOfDepartments;
    vector<string> inputString;
    studentList *universityList = new studentList();
    ifstream in;
    in.open("input.txt");
    string writeTo;
    while(in.good()){
        if (!in.eof()){
            getline(in, writeTo, '\n');
        }
        inputString.push_back(writeTo);
    }
    boost::gregorian::date d , dd;
    d = makeDateFromString("1/25/2011");
    dd = makeDateFromString("7/27/2011");
    //department cs = createADepartment("1024 Computer Science", listOfDepartments);
    //student steve = createAStudent("14 steve glagola econ",universityList);
    //printMajorReport("econ", universityList);
    //addACharge(d,147.25,steve.getStudentID(),"fee",1024,universityList,listOfDepartments);
    //printDepartmentReport("1024",listOfDepartments);
    bool continueInput = true;
    string inputFromUser, continueRunning;
    /*while(continueInput){
        cout << "Please Enter input: " << '\n';
        getline(cin, inputFromUser);
        doDesiredOperation(inputFromUser, universityList, listOfDepartments);
        cout << '\n' << "Do you wish to enter another command?" << '\n' <<
                "Yes/No" << '\n';
        cin >> continueRunning;
        if (continueRunning.compare("Yes")==0){
            continueInput=true;
        }
        else {
            continueInput=false;
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }*/
    for (int i = 0; i < inputString.size(); i++){
        cout << "Line number " << i << '\n';
        doDesiredOperation(inputString[i], universityList, listOfDepartments);
    }
    
    return 0;
}
