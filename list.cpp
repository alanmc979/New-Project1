#include "list.h"
#include "node.h"
#include <iostream>

using namespace std;

list::list (string expression){
	int size = expression.size();
	int count = 0;
	for (int i = 0; i < size; i++){
		if (expression[i] == ' '){
			count++;
		}
	}

	array = new char[size-count];
	int j = 0;

	for (int i = 0; i < size; i++){
		if (expression[i] != ' '){
			array[i-j] = expression[i];
		} else {
			j++;
		}
	}
	array[size-count-1] = '\n';
	cursor = array;
	// cout << array;

}

Node* list::linkedlist (){
	current = new Node(PLUS, 0, 0 ,0);
	
	int i = 1;
	while (cursor[i] != '\n'){
		//create new node
		if (cursor[i] == '('){
			Node *n = new Node(PLUS, 0, 0, current);
			if (current->getLeft() == 0){
				current->Left(n);
			}
			else {
				current->Right(n);
			}
			current = n;
		} 
		//if cursor is pointing to an operator
		else if (current->ifData(cursor[i]) == true) {
			current->setData(cursor[i]);
			
		} 

		else if (current -> typeCheck(cursor[i]) != EXPRESSION){
			if (current -> typeCheck(cursor[i]) == VARIABLE){
				Node *m = new Node(cursor[i], VARIABLE);
				if (current->getLeft() == 0){
					current->Left(m);
				}
				else {
					current->Right(m);
				}
			} else {
				int userInt = cursor[i] - '0';
				Node *m = new Node(userInt, INTEGER);
			
				if (current->getLeft() == 0){
					current->Left(m);
				}
				else {
					current->Right(m);
				}
			}

		}

		//return to previous node 
		else if (cursor[i] == ')'){
			current = current->getParent();
		}
		i++;
	}

	return current;
	
}





