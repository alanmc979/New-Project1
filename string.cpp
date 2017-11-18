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
 	
	list myList(myEXP);
	Node *head = myList.linkedlist();


	Expression myExpression;
	string myInfix = myExpression.print_infix(head);
	string myPrefix = myExpression.print_prefix(head);
	string myPostfix = myExpression.print_postfix(head);

	
	cout << "Infix: " << myInfix << endl;
	cout << "Prefix: " << myPrefix << endl;
	cout << "Postfix: " << myPostfix << endl;

	return 0;


}