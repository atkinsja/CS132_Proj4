/**************************************************************************************************
*
*   File name :			driver.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Driver file initializing an Oxy object and allowing for user input in order to
*	view and change the tree
*
*   Date Written:		in the past
*
*   Date Last Revised:	12/16/2018
****************************************************************************************************/
#include <iostream>
#include "oxy.h"
using namespace std;
int main()
{
	//create Oxy object
	Oxy ox;
	
	//get employees from file
	cout << "Welcome to the Oxy Cookie Company Employee Record Database" << endl;
	ox.populate();	

	char input;
	do
	{
		//menu for options
		cout << "G: Get records from file." << endl;
		cout << "I: Insert record for a new employee." << endl;
		cout << "U: Update record for existing employee." << endl;
		cout << "R: Retrieve and display record for an employee." << endl;
		cout << "L: List records." << endl;
		cout << "S: Save records to file." << endl;
		cout << "D: Delete record." << endl;
		cout << "E: Exit program." << endl;
		cout << "Please select an option: ";
		cin >> input;

		//menu validation
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Incorrect input.\nPlease enter a valid menu option: ";
			cin >> input;
		}
		cin.clear();
		cin.ignore(200, '\n');

		switch (input)
		{
		//get records from file
		case 'g':
		case 'G':
			ox.populate();
			break;
		//insert employee
		case 'i':
		case 'I':
			ox.insertEmployee();
			break;
		//update employee
		case 'u':
		case 'U':
			ox.update();
			break;
		//display employee
		case 'r':
		case 'R':
			ox.retrieveEmployee();
			break;
		//list all employees
		case 'l':
		case 'L':
			ox.listRecords();
			break;
		//write employees to file
		case 's':
		case 'S':
			ox.writeToFile();
			break;
		//delete employee
		case 'd':
		case 'D':
			ox.deleteEmployee();
			break;
		//exit
		case 'e':
		case 'E':
			break;
		//invalide input
		default:
			cout << "Invalid input." << endl;
			break;
		}

		cout << endl;

	} while (input != 'e' && input != 'E');		//end do-while
	return 0;
}


