/**************************************************************************************************
*
*   File name :			maze.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Employee class, implemented in employee.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	12/16/2018
*
*	Class Name:		Employee
*
*	Private data members:
*		char fName[]		-	first name
*		char lName[]		-	last name
*		char ssn[]			-	social security number
*		int age				-	age
*		int dependents		-	number of dependents
*		char code			-	employee code
*		double payRate		-	hourly pay rate
*		double hoursWorked	-	number of hours worked
*
*	Public member functions:
*		Employee		-	constructor for an Employee object
*		operator>>		-	stream extraction operator overload
*		operator<<		-	stream insertion operator overload
*		operator=		-	assignment operator overload
*		operator<		-	less than operator overload
*		operator>		-	greater than operator overload
*		operator<=		-	less than or equal to operator overload
*		operator>=		-	greater than or equal to operator overload
*		operator==		-	equality operator overload
*		operator!=		-	inequality operator overload
*		setFName		-	mutator for fName
*		setLName		-	mutator for LName
*		setSSN			-	mutator for ssn
*		setAge			-	mutator for age
*		setDependents	-	mutator for dependents
*		setCode			-	mutator for code
*		setPayRate		-	mutator for payRate
*		setHoursWorked	-	mutator for hoursWorked
*		getLastName		-	accessor for lName
*		getCode			-	accessor for code
*		getPayRate		-	accessor for payRate
*		getHoursWorked	-	accessor for hoursWorked
****************************************************************************************************/
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define NAMEBUF 21
#define SSNBUF 12
#include <iostream>
#include <fstream>
#include <iomanip>
class Employee
{
public:
	Employee();
	//operator overloads
	friend std::istream& operator>>(std::istream&, Employee&);
	friend std::ostream& operator<<(std::ostream&, const Employee&);
	Employee& operator=(const Employee&);
	bool operator<(const Employee&);
	bool operator>(const Employee&);
	bool operator<=(const Employee&);
	bool operator>=(const Employee&);
	bool operator==(const Employee&);
	bool operator!=(const Employee&);

	//mutators
	void setFName(char[NAMEBUF]);
	void setLName(char[NAMEBUF]);
	void setSSN(char[SSNBUF]);
	void setAge(int);
	void setDependents(int);
	void setCode(char);
	void setPayRate(double);
	void setHoursWorked(double);

	//accessors
	char* getLastName();
	char getCode();
	double getPayRate();
	double getHoursWorked();

private:
	char fName[NAMEBUF];
	char lName[NAMEBUF];
	char ssn[SSNBUF];
	int age;
	int dependents;
	char code;
	double payRate;
	double hoursWorked;
};
#endif // !EMPLOYEE_H_
