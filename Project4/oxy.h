/**************************************************************************************************
*
*   File name :			Oxy.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Oxy class, implemented in oxy.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	12/16/2018
*
*	Class Name:		Oxy
*
*	Private data members:
*		bool populated	-	boolean determining if the tree has data or not
*
*	Private member function:
*		preOrderWrite	-	writes tree to output stream using preorder traversal
*		printInOrder	-	display tree using inorder traveral
*		deleteTree		-	deletes the entire tree
*		validateName	-	validates a file name for input
*		isValidSSN		-	validates a social security number
*		validateInt		-	validates any integer input
*		validateDouble	-	validates any double input
*
*	Public member functions:
*		Oxy					-	constructor for an Oxy object
*		populate			-	gets information from a file and stores it in the tree
*		insertEmployee		-	inserts a new employee into the tree
*		update				-	updates existing employee information fields
*		retrieveEmployee	-	displays information about a specific employee
*		listRecords			-	displays the tree with an inorder traversal
*		writeToFile			-	writes tree to a file using preOrderWrite
*		deleteEmployee		-	delete a specific employee
****************************************************************************************************/
#ifndef OXY_H_
#define OXY_H_
#define FILENAMEBUF 50
#include "employee.h"
#include "tree.h"

class Oxy : public tree<Employee>
{
public:
	Oxy();
	void populate();
	void insertEmployee();
	void update();
	void retrieveEmployee();
	void listRecords();
	void writeToFile();
	void deleteEmployee();
	
private:
	void printInOrder(TreeNode<Employee>*, char[4]);
	void preOrderWrite(TreeNode<Employee>*, ofstream&);
	void deleteTree(TreeNode<Employee>*&);
	void validateName(char[], int buffer);
	bool isValidSSN(char[]);
	void validateInt(int&, int);
	void validateDouble(double&, int);
	bool populated;
};
#endif // !OXY_H_
