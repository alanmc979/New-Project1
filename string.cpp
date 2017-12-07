#include "string.h"
#include "expression.h"
#include "list.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;


int main(){


	string myEXP, myEXP1,myEXP2;
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
	int evaluated = myExpression.evaluate(myInfix);
	cout << "The expression equals to " << evaluated <<endl;

	cout << "Enter expression1 to compare: ";
	getline(cin, myEXP1);
 	
	list myList1(myEXP1);
	head = myList1.linkedlist();


	Expression myExpression1;
	string myInfix1 = myExpression1.print_infix(head);

	int x = myExpression1.evaluate(myInfix1);

	cout << "Enter expression2 to compare: ";
	getline(cin, myEXP2);
 	
	list myList2(myEXP2);
	head = myList2.linkedlist();


	Expression myExpression2;
	string myInfix2 = myExpression2.print_infix(head);

	int y = myExpression2.evaluate(myInfix2);

	cout<< "Expression 1 "<<myExpression.compare(x,y)<<" Expression 2"<<endl;


	return 0;


}