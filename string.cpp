#include "string.h"
#include "expression.h"
#include "list.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;


int main(){


	string myEXP;
	cout << "Enter an expression: ";
	getline(cin, myEXP);
 	
 	//cout << myEXP;
	list myList(myEXP);
	Node *head = myList.linkedlist();


	Expression myExpression;
	string myInfix = myExpression.print_infix(head);
	
	cout << myInfix << endl;

	// for (int i = 0; i < 5; i++){
	//cout << myArray << endl;
	//cout << myInfix << endl;
	//}

	return 0;


}