#include "expression.h"
#include <string>
#include <iostream>
using namespace std;

Expression::Expression(){
	
}


string Expression::print_infix(Node* pointer) const {
	string userStr;
	int x = 1;
	
	while (x != 0){
		if ((pointer -> getLeft() -> nodeCheck() != EXPRESSION) && 
		(pointer -> getRight() -> nodeCheck()!= EXPRESSION)) {
		userStr += pointer -> getLeft() -> getVar();
		userStr += pointer -> getData();
		userStr += pointer -> getRight() -> getVal();
		return userStr;
		}
			
		if (pointer -> getLeft() -> nodeCheck() == EXPRESSION){
			pointer = pointer -> getLeft();
			userStr += Expression::print_infix(pointer);
			pointer = pointer -> getParent();
			userStr += pointer -> getData();
		} else {
			userStr += pointer -> getLeft() -> getVar();
			userStr += pointer -> getData();
			pointer = pointer -> getRight();
			userStr += Expression::print_infix(pointer);
			return userStr;
		}
		if (pointer -> getRight() -> nodeCheck() == EXPRESSION){
			pointer = pointer -> getRight();
			userStr += Expression::print_infix(pointer);
			pointer = pointer -> getParent();
		} else {
			userStr += pointer -> getRight() -> getVal();
			return userStr;
		}

		x = 0;
	}


	
	return userStr;

}

string Expression::print_prefix(Node*pointer) const {


	
}







