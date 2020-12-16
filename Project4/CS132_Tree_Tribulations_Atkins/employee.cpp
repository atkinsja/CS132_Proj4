/**************************************************************************************************
*
*   File name :			employee.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Implementations of the functions defined in employee.h, which contains the functionality of
*	an Employee object, which includes operator overloads and required accessor/mutator functions
*
*   Date Written:		in the past
*
*   Date Last Revised:	12/16/2018
****************************************************************************************************/

#include "employee.h"
using namespace std;

/*******************************************************************************************
*	Function Name:			Employee()	-	the constructor
*	Purpose:				This constructor creates an Employee object and sets default
*							values to the created object
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Employee::Employee()
{
	strcpy_s(fName, "NullFirstName");
	strcpy_s(lName, "NullLastName");
	strcpy_s(ssn, "NullSSN");
	age = 0;
	dependents = 0;
	code = '0';
	payRate = 0;
	hoursWorked = 0;
}

/*******************************************************************************************
*	Function Name:			operator>>
*	Purpose:				Overloads the stream extraction operator to read an Employee
*							from a formatted text file
*	Input Parameters:		istream&	-	reference to the input stream
*							Employee&	-	reference to an Employee object to input into
*	Output Parameters:		istream&	-	reference to the input stream
*							Employee&	-	reference to an Employee object to input into
*	Return value:			istream&	-	the input stream
********************************************************************************************/
istream& operator>>(istream& is, Employee& emp)
{
	is.getline(emp.lName, NAMEBUF, ',');
	is.ignore();
	is.getline(emp.fName, NAMEBUF, '\n');
	is.getline(emp.ssn, SSNBUF);
	is >> emp.age;
	is >> emp.dependents;
	is >> emp.code;
	is >> emp.payRate;
	is >> emp.hoursWorked;
	is.ignore(200, '\n');

	return is;
}

/*******************************************************************************************
*	Function Name:			operator<<
*	Purpose:				Overloads the stream insertion operator to output an Employee
*							to an ouput stream
*	Input Parameters:		ostream&	-	reference to the output stream
*							Employee&	-	reference to an Employee object to output
*	Output Parameters:		ostream&	-	reference to the output stream
*							Employee&	-	reference to an Employee object to output
*	Return value:			ostream&	-	the output stream
********************************************************************************************/
ostream& operator<<(ostream& os, const Employee& emp)
{
	os << endl;
	os << "Last Name: " << emp.lName << endl;
	os << "First Name: " << emp.fName << endl;
	os << "Social Security Number: " << emp.ssn << endl;
	os << "Age: " << emp.age << endl;
	os << "Number of dependents: " << emp.dependents << endl;
	os << "Employee code: " << emp.code << endl;
	os << "Hourly pay rate: " << fixed << setprecision(2) << emp.payRate << endl;
	os << "Hours worked: " << emp.hoursWorked << endl;
	os << endl;
	return os;
}

/*******************************************************************************************
*	Function Name:			operator=
*	Purpose:				Overloads the assignment operator to allow an Employee to be
*							assigned to another Employee
*	Input Parameters:		Employee&	-	the employee to be assigned to
*	Output Parameters:		Employee&	-	the employee to be assigned to
*	Return value:			Employee&	-	the employee to assign
********************************************************************************************/
Employee& Employee::operator=(const Employee& emp)
{
	strcpy_s(this->fName, emp.fName);
	strcpy_s(this->lName, emp.lName);
	strcpy_s(this->ssn, emp.ssn);
	this->age = emp.age;
	this->dependents = emp.dependents;
	this->code = emp.code;
	this->payRate = emp.payRate;
	this->hoursWorked = emp.hoursWorked;
	return *this;
}

/*******************************************************************************************
*	Function Name:			operator<
*	Purpose:				Overloads the less than operator to determine if an Employee is
*							less than another Employee
*	Input Parameters:		Employee&	-	the employee to be compared to
*	Output Parameters:		Employee&	-	the employee to be compared to
*	Return value:			Employee&	-	the employee to compare
********************************************************************************************/
bool Employee::operator<(const Employee& emp)
{
	if (strcmp(this->lName, emp.lName) < 0)
		return true;
	else
		return false;
}

/*******************************************************************************************
*	Function Name:			operator>
*	Purpose:				Overloads the greater than operator to determine if an Employee is
*							greater than another Employee
*	Input Parameters:		Employee&	-	the employee to be compared to
*	Output Parameters:		Employee&	-	the employee to be compared to
*	Return value:			Employee&	-	the employee to compare
********************************************************************************************/
bool Employee::operator>(const Employee& emp)
{
	if (strcmp(this->lName, emp.lName) > 0)
		return true;
	else
		return false;
}

/*******************************************************************************************
*	Function Name:			operator<=
*	Purpose:				Overloads the less than or equal to operator to determine if 
							an Employee is less than or equal to another Employee
*	Input Parameters:		Employee&	-	the employee to be compared to
*	Output Parameters:		Employee&	-	the employee to be compared to
*	Return value:			Employee&	-	the employee to compare
********************************************************************************************/
bool Employee::operator<=(const Employee& emp)
{
	if (strcmp(this->lName, emp.lName) <= 0)
		return true;
	else
		return false;
}

/*******************************************************************************************
*	Function Name:			operator>=
*	Purpose:				Overloads the greater than or equal to operator to determine if
							an Employee is greater than or equal to another Employee
*	Input Parameters:		Employee&	-	the employee to be compared to
*	Output Parameters:		Employee&	-	the employee to be compared to
*	Return value:			Employee&	-	the employee to compare
********************************************************************************************/
bool Employee::operator>=(const Employee& emp)
{
	if (strcmp(this->lName, emp.lName) >= 0)
		return true;
	else
		return false;
}

/*******************************************************************************************
*	Function Name:			operator==
*	Purpose:				Overloads the equality operator to determine if an Employee is
*							equal to another Employee
*	Input Parameters:		Employee&	-	the employee to be compared to
*	Output Parameters:		Employee&	-	the employee to be compared to
*	Return value:			Employee&	-	the employee to compare
********************************************************************************************/
bool Employee::operator==(const Employee& emp)
{
	if (strcmp(this->lName, emp.lName) == 0)
		return true;
	else
		return false;
}

/*******************************************************************************************
*	Function Name:			operator!=
*	Purpose:				Overloads the inequality operator to determine if an Employee is
*							not equal to another Employee
*	Input Parameters:		Employee&	-	the employee to be compared to
*	Output Parameters:		Employee&	-	the employee to be compared to
*	Return value:			Employee&	-	the employee to compare
********************************************************************************************/
bool Employee::operator!=(const Employee& emp)
{
	if (strcmp(this->lName, emp.lName) != 0)
		return true;
	else
		return false;
}

/*******************************************************************************************
*	Function Name:			setFName
*	Purpose:				Mutator to change the first name of an Employee
*	Input Parameters:		char newFName[]	-	the new first name
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setFName(char newFName[NAMEBUF])
{
	strcpy_s(this->fName, newFName);
}

/*******************************************************************************************
*	Function Name:			setLName
*	Purpose:				Mutator to change the last name of an Employee
*	Input Parameters:		char newLName[]	-	the new last name
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setLName(char newLName[NAMEBUF])
{
	strcpy_s(this->lName, newLName);
}

/*******************************************************************************************
*	Function Name:			setSSN
*	Purpose:				Mutator to change the social security number of an Employee
*	Input Parameters:		char newSSN[]	-	the new social securty number
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setSSN(char newSSN[SSNBUF])
{
	strcpy_s(this->ssn, newSSN);
}

/*******************************************************************************************
*	Function Name:			setAge
*	Purpose:				Mutator to change the age of an Employee
*	Input Parameters:		int newAge	-	the new age
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setAge(int newAge)
{
	this->age = newAge;
}

/*******************************************************************************************
*	Function Name:			setDependents
*	Purpose:				Mutator to change the number of dependents of an Employee
*	Input Parameters:		char newDep	-	the new number of dependents
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setDependents(int newDep)
{
	this->dependents = newDep;
}

/*******************************************************************************************
*	Function Name:			setCode
*	Purpose:				Mutator to change the employee code of an Employee
*	Input Parameters:		char newDep	-	the new employee code
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setCode(char newCode)
{
	this->code = newCode;
}

/*******************************************************************************************
*	Function Name:			setPayRate
*	Purpose:				Mutator to change the pay rate of an Employee
*	Input Parameters:		double newPay	-	the new pay rate
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setPayRate(double newPay)
{
	this->payRate = newPay;
}

/*******************************************************************************************
*	Function Name:			setHoursWorked
*	Purpose:				Mutator to change the number of hours worked of an Employee
*	Input Parameters:		double newHours	-	the new number of hours worked
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Employee::setHoursWorked(double newHours)
{
	this->hoursWorked = newHours;
}

/*******************************************************************************************
*	Function Name:			getLastName
*	Purpose:				Accessor the get the last name of an Employee
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			char*	-	last name of an Employee
********************************************************************************************/
char* Employee::getLastName()
{
	return lName;
}

/*******************************************************************************************
*	Function Name:			getHoursWorked
*	Purpose:				Accessor the get the number of hours worked of an Employee
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			double	-	the number of hours worked
********************************************************************************************/
double Employee::getHoursWorked()
{
	return hoursWorked;
}

/*******************************************************************************************
*	Function Name:			getPayRate
*	Purpose:				Accessor the get the pay rate of an Employee
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			double	-	the pay rate
********************************************************************************************/
double Employee::getPayRate()
{
	return payRate;
}

/*******************************************************************************************
*	Function Name:			getCode
*	Purpose:				Accessor the get the employee code of an Employee
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			char	-	the employee code
********************************************************************************************/
char Employee::getCode()
{
	return code;
}