/**************************************************************************************************
*
*   File name :			oxy.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Implementations of the functions defined in oxy.h, which is derived from a binary search tree
*	defined in tree.t.
*
*   Date Written:		in the past
*
*   Date Last Revised:	12/16/2018
****************************************************************************************************/

#include "oxy.h"

/*******************************************************************************************
*	Function Name:			Oxy()	-	the constructor
*	Purpose:				This constructor creates an Oxy object and sets a boolean
*							variable determining whether the tree has data to false
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Oxy::Oxy()
{
	populated = false;
}

/*******************************************************************************************
*	Function Name:			preOrderWrite
*	Purpose:				Uses a preorder traversal and the overloaded stream insertion
*							operator to write the tree to a file
*	Input Parameters:		TreeNode<Employee>*	-	pointer to a node in the tree
*							ofstream&			-	reference to the output stream
*	Output Parameters:		ofstream&			-	reference to the output stream
*	Return value:			none
********************************************************************************************/
void Oxy::preOrderWrite(TreeNode<Employee>* p, ofstream& outFile)
{
	if (p)
	{
		outFile << p->TreeData;
		preOrderWrite(p->left, outFile);
		preOrderWrite(p->right, outFile);
	}
}

/*******************************************************************************************
*	Function Name:			printInOrder
*	Purpose:				Uses an inorder traversal and the overloaded stream insertion
*							operator to display the employees in the tree in alphabetical
*							order
*	Input Parameters:		TreeNode<Employee>*	-	pointer to a node in the tree
*							char selection[]	-	subset of the tree to print
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::printInOrder(TreeNode<Employee>* p, char selection[4])
{
	if (p)
	{
		//display all employees
		if (strcmp(selection, "ALL\0") == 0)
		{
			printInOrder(p->left, selection);
			cout << p->TreeData;
			printInOrder(p->right, selection);
		}

		//display office employees
		else if (strcmp(selection, "OFF\0") == 0)
		{
			printInOrder(p->left, selection);
			if (p->TreeData.getCode() == 'O')
				cout << p->TreeData;
			printInOrder(p->right, selection);
		}

		//display factory employees
		else if (strcmp(selection, "FAC\0") == 0)
		{
			printInOrder(p->left, selection);
			if (p->TreeData.getCode() == 'F')
				cout << p->TreeData;
			printInOrder(p->right, selection);
		}

		//display sales employees
		else if (strcmp(selection, "SAL\0") == 0)
		{
			printInOrder(p->left, selection);
			if (p->TreeData.getCode() == 'S')
				cout << p->TreeData;
			printInOrder(p->right, selection);
		}
		
		//invalid input
		else
		{
			cout << "Invalid option" << endl;
			return;
		}
	}
}

/*******************************************************************************************
*	Function Name:			deleteTree
*	Purpose:				Uses a postorder traversal to delete the tree
*	Input Parameters:		TreeNode<Employee>*&	-	reference to a TreeNode pointer
*	Output Parameters:		TreeNode<Employee>*&	-	reference to a TreeNode pointer
*	Return value:			none
********************************************************************************************/
void Oxy::deleteTree(TreeNode<Employee>*& p)
{
	if (p)
	{
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
		p = NULL;
	}
}

/*******************************************************************************************
*	Function Name:			listRecords
*	Purpose:				Uses the printInOrder function to display either all employees
*							or a subset of them based on job code
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::listRecords()
{
	
	char selection[4];
	cout << endl;
	cout << "ALL - All employees" << endl;
	cout << "OFF - Office employees" << endl;
	cout << "FAC - Factory employees" << endl;
	cout << "SAL - Salesmen" << endl;
	cout << "Which records would you like to display: ";
	cin >> selection;
	cin.clear();
	cin.ignore(200, '\n');

	//makes selection case independent
	for(unsigned int i = 0; i < strlen(selection); i++)
		selection[i] = toupper(selection[i]);

	//display all employees
	if (strcmp(selection, "ALL\0") == 0)
		printInOrder(root, selection);

	//display office employees
	else if (strcmp(selection, "OFF\0") == 0)
		printInOrder(root, selection);

	//display factory employees
	else if (strcmp(selection, "FAC\0") == 0)
		printInOrder(root, selection);

	//display sales employees
	else if (strcmp(selection, "SAL\0") == 0)
		printInOrder(root, selection);

	//invalid option
	else
	{
		cout << "Please enter a valid option" << endl;
		return;
	}
	
}

/*******************************************************************************************
*	Function Name:			populate
*	Purpose:				Uses the overload stream extraction operator to read in 
*							employees from a file and insert them into the binary tree
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::populate()
{
	//get file name
	char inFileName[FILENAMEBUF];
	cout << "Enter the name of the employee records file: ";
	cin >> inFileName;
	cin.clear();
	cin.ignore(200, '\n');

	Employee temp;		//employee to add

	ifstream inFile;
	inFile.open(inFileName);

	//make sure file exists
	while (!inFile)
	{
		cout << "Error opening " << inFileName << endl;
		cout << "Enter the name of the employee records file: ";
		cin >> inFileName;
		cin.clear();
		cin.ignore(200, '\n');
		inFile.open(inFileName);
	}

	//if the tree is already populated, delete it and read from the new file
	if (populated)
	{
		//temp values for employee
		char tempLName[NAMEBUF];
		char tempFName[NAMEBUF];
		char tempSSN[SSNBUF];
		int tempAge;
		int tempDep;
		char tempCode;
		double tempPayRate;
		double tempHoursWorked;

		//delete the current tree
		deleteTree(root);

		//read from previously output file
		inFile.ignore(200, ':');
		inFile >> tempLName;
		while (inFile)
		{
			temp.setLName(tempLName);
			
			inFile.ignore(200, ':');
			inFile >> tempFName;
			temp.setFName(tempFName);
			

			inFile.ignore(200, ':');
			inFile >> tempSSN;
			temp.setSSN(tempSSN);

			inFile.ignore(200, ':');
			inFile >> tempAge;
			temp.setAge(tempAge);

			inFile.ignore(200, ':');
			inFile >> tempDep;
			temp.setDependents(tempDep);

			inFile.ignore(200, ':');
			inFile >> tempCode;
			temp.setCode(tempCode);

			inFile.ignore(200, ':');
			inFile >> tempPayRate;
			temp.setPayRate(tempPayRate);

			inFile.ignore(200, ':');
			inFile >> tempHoursWorked;
			temp.setHoursWorked(tempHoursWorked);

			insert(temp);

			inFile.ignore(200, ':');
			inFile >> tempLName;
		}
		//tree is populated
		inFile.close();
		cout << "Records populated." << endl;
		populated = true;
	}

	//tree is not populated
	else
	{
		inFile >> temp;
		while (inFile)
		{
			insert(temp);
			inFile >> temp;
		}
		//tree is populated
		inFile.close();
		cout << "Records populated." << endl;
		populated = true;
	}
}

/*******************************************************************************************
*	Function Name:			insertEmployee
*	Purpose:				Gets information about the employee from the user, and then
*							inserts that employee into the binary tree
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::insertEmployee()
{
	Employee newEmp;		//employee to add
	char fName[NAMEBUF];
	char lName[NAMEBUF];
	char ssn[SSNBUF];
	int age;
	int dependents;
	char code;
	double payRate;
	double hoursWorked;
	
	//get information about the employee from the user
	cout << "New Employee Record" << endl;

	//last name
	cout << "Enter the last name of the employee: ";
	cin.getline(lName, NAMEBUF);
	validateName(lName, NAMEBUF);
	lName[0] = toupper(lName[0]);
	newEmp.setLName(lName);

	//first name
	cout << "Enter the first name of the employee: ";
	cin.getline(fName, NAMEBUF);
	validateName(fName, NAMEBUF);
	fName[0] = toupper(fName[0]);
	newEmp.setFName(fName);

	//social security number
	cout << "Enter the social security number of the employee (XXX-XX-XXXX): ";
	cin.getline(ssn, SSNBUF);

	//validate social security number
	while (!isValidSSN(ssn))
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Invalid social security number." << endl;
		cout << "Enter the social security number of the employee (XXX-XX-XXXX): ";
		cin.getline(ssn, SSNBUF);
	}
	
	newEmp.setSSN(ssn);

	//age
	cout << "Enter the age of the employee: ";
	validateInt(age, 0);
	newEmp.setAge(age);

	//dependents
	cout << "Enter the number of dependents: ";
	validateInt(dependents, 0);
	newEmp.setDependents(dependents);

	//employee code
	cout << "O - Office" << endl;
	cout << "F - Factory" << endl;
	cout << "S - Salesman" << endl;
	cout << "Enter the employee code: ";
	cin >> code;
	cin.clear();
	cin.ignore(200, '\n');

	//employee code validation
	code = toupper(code);
	while (code != 'O' && code != 'F' && code != 'S')
	{
		cout << "Invalid code." << endl;
		cout << "O - Office" << endl;
		cout << "F - Factory" << endl;
		cout << "S - Salesman" << endl;
		cout << "Enter the employee code: ";
		cin >> code;
		cin.clear();
		cin.ignore(200, '\n');
		code = toupper(code);
	}
	newEmp.setCode(code);


	//hourly pay rate
	cout << "Enter the hourly pay rate of the employee: ";
	validateDouble(payRate, 0);
	newEmp.setPayRate(payRate);


	//number of hours
	cout << "Enter the number of hours the employee worked: ";
	validateDouble(hoursWorked, 0);
	newEmp.setHoursWorked(hoursWorked);

	//insert employee into binary tree
	insert(newEmp);

	cout << "Employee added." << endl;
}

/*******************************************************************************************
*	Function Name:			update
*	Purpose:				Finds a user input employee in the tree by last name, then
*							allows the user to update any of the fields in the employee
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::update()
{
	TreeNode<Employee> *current;
	Employee emp;
	int input;
	char lName[NAMEBUF];
	char newFName[NAMEBUF];
	char newLName[NAMEBUF];
	char newSSN[SSNBUF];
	int newAge;
	int newDep;
	char newCode;
	double newPayRate;
	double newHoursWorked;
	
	//get last name to search for
	cout << "Enter the last name of the employee to update: ";
	cin.getline(lName, NAMEBUF);
	emp.setLName(lName);
	
	//search tree for employee
	current = root;
	while (current && (current->TreeData != emp))
	{
		if (current->TreeData > emp)
			current = current->left;
		else current = current->right;
	}

	//employee not in the tree
	if (!current)
	{
		cout << "Employee not found." << endl;
		return;
	}

	//employee found
	emp = current->TreeData;
	
	//update information
	do 
	{
		//field to update
		cout << "1. First Name" << endl;
		cout << "2. Last Name" << endl;
		cout << "3. Social Security Number" << endl;
		cout << "4. Age" << endl;
		cout << "5. Number of dependents" << endl;
		cout << "6. Employee Code" << endl;
		cout << "7. Hourly Pay Rate" << endl;
		cout << "8. Hours worked" << endl;
		cout << "9. Finish updating" << endl;
		cout << "Select the option you would like to change: ";
		cin >> input;
		cin.clear();
		cin.ignore();

		switch (input)
		{
		case 1:
			//update first name
			cout << "Enter the updated first name: ";
			cin.getline(newFName, NAMEBUF);
			validateName(newFName, NAMEBUF);
			newFName[0] = toupper(newFName[0]);
			emp.setFName(newFName);
			break;
		case 2:
			//update last name
			cout << "Enter the updated last name: ";
			cin.getline(newLName, NAMEBUF);
			validateName(newLName, NAMEBUF);
			newLName[0] = toupper(newLName[0]);
			emp.setLName(newLName);
			break;
		case 3:
			//update social security number
			cout << "Enter the updated social security number (XXX-XX-XXXX): ";
			cin.getline(newSSN, SSNBUF);
			while (!isValidSSN(newSSN))
			{
				cin.clear();
				cin.ignore(200, '\n');
				cout << "Invalid social security number." << endl;
				cout << "Enter the social security number of the employee (XXX-XX-XXXX): ";
				cin.getline(newSSN, SSNBUF);
			}
			break;
		case 4:
			//update age
			cout << "Enter the updated age: ";
			validateInt(newAge, 0);
			emp.setAge(newAge);
			break;
		case 5:
			//update number of dependents
			cout << "Enter the updated number of dependents: ";
			validateInt(newDep, 0);
			emp.setDependents(newDep);
			break;
		case 6:
			//update employee code
			cout << "O - Office" << endl;
			cout << "F - Factory" << endl;
			cout << "S - Salesman" << endl;
			cout << "Enter the updated employee code: ";
			cin >> newCode;
			cin.clear();
			cin.ignore(200, '\n');
			newCode = toupper(newCode);
			while (newCode != 'O' && newCode != 'F' && newCode != 'S')
			{
				cout << "Invalid code." << endl;
				cout << "O - Office" << endl;
				cout << "F - Factory" << endl;
				cout << "S - Salesman" << endl;
				cout << "Enter the employee code: ";
				cin >> newCode;
				cin.clear();
				cin.ignore(200, '\n');
				newCode = toupper(newCode);
			}
			emp.setCode(newCode);
			break;
		case 7:
			//update hourly pay rate
			cout << "Enter the updated hourly pay rate: ";
			validateDouble(newPayRate, 0);
			emp.setPayRate(newPayRate);
			break;
		case 8:
			//update number of hours worked
			cout << "Enter the updated number of hours worked: ";
			validateDouble(newHoursWorked, 0);
			emp.setHoursWorked(newHoursWorked);
			break;
		case 9:
			//delete the old data and insert the new data
			SearchAndDestroy(current->TreeData);
			insert(emp);
			cout << "Employee updated." << endl;
			break;
		default:
			//invalid option
			cout << "Invalid selection. Please select an option 1-9";
			break;
		}	//end switch
	} while (input != 9);	//end do-while

}

/*******************************************************************************************
*	Function Name:			retrieveEmployee
*	Purpose:				Displays information about a user input employee
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::retrieveEmployee()
{
	TreeNode<Employee> *current;
	Employee emp;
	double calculatedPay;
	
	char lName[NAMEBUF];

	//get name of employee to search for
	cout << "Enter the last name of the employee to display: ";
	cin.getline(lName, NAMEBUF);
	validateName(lName, NAMEBUF);
	lName[0] = toupper(lName[0]);
	emp.setLName(lName);

	//search for employee
	current = root;
	while (current && (current->TreeData != emp))
	{
		if (current->TreeData > emp)
			current = current->left;
		else current = current->right;
	}

	//employee not found
	if (!current)
	{
		cout << "Employee not found." << endl;
		return;
	}

	//determine pay
	calculatedPay = current->TreeData.getPayRate() * current->TreeData.getHoursWorked();

	//display employee
	cout << endl << current->TreeData;
	cout << "Calculated pay: " << calculatedPay << endl;

}

/*******************************************************************************************
*	Function Name:			writeToFile
*	Purpose:				Stores the binary tree using a preorder traversal in a user
*							specified file
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::writeToFile()
{
	char outFileName[FILENAMEBUF];
	ofstream outFile;
	//get name of the file to store the tree in
	cout << "Enter the name of the file to save the records to: ";
	cin >> outFileName;
	cin.clear();
	cin.ignore(200, '\n');

	outFile.open(outFileName);

	//write to file using preOrderWrite
	preOrderWrite(root, outFile);
	outFile.close();
	cout << "Records saved to " << outFileName << endl;
}

/*******************************************************************************************
*	Function Name:			deleteEmployee
*	Purpose:				Deletes an employee specified by last name
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::deleteEmployee()
{
	TreeNode<Employee> *current;
	Employee emp;

	char lName[NAMEBUF];

	//get last name of employee to delete
	cout << "Enter the last name of the employee to delete: ";
	cin.getline(lName, NAMEBUF);
	validateName(lName, NAMEBUF);
	lName[0] = toupper(lName[0]);
	emp.setLName(lName);

	//search for employee
	current = root;
	while (current && (current->TreeData != emp))
	{
		if (current->TreeData > emp)
			current = current->left;
		else current = current->right;
	}

	//employee not found
	if (!current)
	{
		cout << "Employee not found." << endl;
		return;
	}

	//delete employee
	SearchAndDestroy(current->TreeData);

	cout << "Employee deleted." << endl;
}

/*******************************************************************************************
*	Function Name:			validateName
*	Purpose:				Validate a filename to make sure it doesn't overflow the buffer
*	Input Parameters:		char name[]	-	filename to validate
*							int buffer	-	max size of filename
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Oxy::validateName(char name[], int buffer)
{
	//filename too large
	while (strlen(name) == (buffer - 1) && cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "File name too long. Enter a filename less than " << buffer - 1 << " characters: ";
		cin.getline(name, buffer);
	}
}

/*******************************************************************************************
*	Function Name:			isValidSSN
*	Purpose:				Validates a social security number to ensure it is in the correct
*							formate
*	Input Parameters:		char ssn[]	-	social security number to validate
*	Output Parameters:		none
*	Return value:			bool		-	true of ssn is valid, false if not
********************************************************************************************/
bool Oxy::isValidSSN(char ssn[])
{
	bool hasDigit = true;
	bool hasHyphen = true;

	if (strlen(ssn) == 11)
	{
		for (int i = 0; i < 11; i++)
		{
			if (i < 3 || (i > 3 && i < 6) || i > 6)
			{
				if (!(isdigit(ssn[i]))) hasDigit = false;

			}
			if (i == 3 || i == 6)
			{
				if (!(ssn[i] == '-')) hasHyphen = false;
			}
		}

		if (hasDigit == true && hasHyphen == true) 
			return true;

	}
	return false;
}

/*******************************************************************************************
*	Function Name:			validateInt
*	Purpose:				Validate an integer to make sure it is an integer and above
*							an input lower bound
*	Input Parameters:		int& input		-	the integer to validate
*							int lowerbound	-	the lowest valid value for the input
*	Output Parameters:		int& input		-	the integer to validate
*	Return value:			none
********************************************************************************************/
void Oxy::validateInt(int& input, int lowerBound)
{
	
	cin >> input;

	//prompt the user while the input is not an integer or is below the lower bound
	while (cin.fail() || cin.peek() != '\n' || input < lowerBound)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Incorrect input.\nPlease enter a valid integer greater than or equal to " << lowerBound << endl;

		cin >> input;
	}
}

/*******************************************************************************************
*	Function Name:			validateDouble
*	Purpose:				Validate a double to make sure it is a double and above
*							an input lower bound
*	Input Parameters:		double& input	-	the double to validate
*							int lowerbound	-	the lowest valid value for the input
*	Output Parameters:		double& input	-	the double to validate
*	Return value:			none
********************************************************************************************/
void Oxy::validateDouble(double& input, int lowerBound)
{

	cin >> input;

	//prompt the user while the input is not an integer or is below the lower bound
	while (cin.fail() || cin.peek() != '\n' || input < lowerBound)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Incorrect input.\nPlease enter a valid number greater than or equal to " << lowerBound << endl;

		cin >> input;
	}
}
