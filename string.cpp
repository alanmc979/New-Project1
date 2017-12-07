#include "string.h"
#include "expression.h"
#include "list.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;


int main(){

	string myEXP, myEXP1, myEXP2;
	char answer = 'y';
	char choice;

	 while (answer == 'y') {

		cout << "Type 1 for Expression Evaluation, " << 
			"Type 2 for Expression Comparison: " << endl;
		cin >> choice;
		while(choice!='1' and choice!='2'){
			cout<<"Invalid input."<<endl<<"Please Type 1 for Expression Evaluation, " << 
			"Type 2 for Expression Comparison: " << endl;
			cin>> choice;
		}

		if (choice == '1'){

			cout << "Enter an expression: ";
			cin>> myEXP;
 	
			list myList(myEXP);
			Node *head = myList.linkedlist();

			Expression myExpression;
			string myInfix = myExpression.print_infix(head);
			string myPrefix = myExpression.print_prefix(head);
			string myPostfix = myExpression.print_postfix(head);
			
			
			cout << "Infix: " << myInfix << endl;
			cout << "Prefix: " << myPrefix << endl;
			cout << "Postfix: " << myPostfix << endl;
			int evaluated = myExpression.evaluate(head);
			cout << "The expression equals to " << evaluated <<endl;
		} 
		else if (choice == '2'){
			cout << "Enter first expressions: ";
			cin>>myEXP1;
			cout << "Enter second expression: ";
			cin>>myEXP2;

			list myList1(myEXP1); list myList2(myEXP2);
			Node *head1 = myList1.linkedlist();
			Node *head2 = myList2.linkedlist();

			Expression myExpression1;
			Expression myExpression2;
			int eval1 = myExpression1.evaluate(head1);
			int eval2 = myExpression2.evaluate(head2);
			cout <<myEXP1<<"="<<eval1<<" "<< myExpression1.compare(eval1, eval2)<<" "<<myEXP2<<"="<<eval2 << endl;
			cout<<"Expression 1 "<<myExpression1.compare(eval1, eval2)<<" Expression 2"<<endl;
		} 

		cout << "Type 'y' to continue or type 'n' to end program: " << endl;
		cin >> answer;
		while(answer!='y' and answer!='n'){
			cout<<"Invalid input. Please type 'y' to continue or type 'n' to end program: "<<endl;
			cin>> answer;
		}
	}

	return 0;


}