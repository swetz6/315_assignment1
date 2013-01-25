/* 
 * File:   department.h
 * Author: patrick
 *
 * Created on January 22, 2013, 8:56 PM
 */
#include <iostream>
#include <string>
#include <vector>

#ifndef DEPARTMENT_H
#define	DEPARTMENT_H

class department {
	int departmentID;
	std::string departmentName;
public:
	department(int departID, std::string departName)
		:departmentID(departID),departmentName(departName){}
	int getDepartmentID(){return departmentID;}
	std::string getDepartmentName(){return departmentName;}
};
#endif	/* DEPARTMENT_H */

