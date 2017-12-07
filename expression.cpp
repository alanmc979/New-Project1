#include "expression.h"
#include <string>
#include <stack>
#include <stdlib.h>
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
			userStr += "(";
			if (pointer -> getLeft() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getLeft() -> getVar();
			} else {
				userStr += pointer -> getLeft() -> getVal();
			}

			userStr += pointer -> getData();
			if (pointer -> getRight() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getRight() -> getVar();
			} else {
				userStr += pointer -> getRight() -> getVal();
			}
			userStr += ")";
			return userStr;
		}
			
		if (pointer -> getLeft() -> nodeCheck() == EXPRESSION){
			userStr += "(";
			pointer = pointer -> getLeft();
			userStr += Expression::print_infix(pointer);
			pointer = pointer -> getParent();
			userStr += pointer -> getData();
		} else {
			userStr += "(";
			if (pointer -> getLeft() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getLeft() -> getVar();
			} else {
				userStr += pointer -> getLeft() -> getVal();
			}
			userStr += pointer -> getData();
			pointer = pointer -> getRight();
			userStr += Expression::print_infix(pointer);
			userStr += ")";
			return userStr;
		}
		if (pointer -> getRight() -> nodeCheck() == EXPRESSION){
			
			pointer = pointer -> getRight();
			userStr += Expression::print_infix(pointer);
			pointer = pointer -> getParent();
			userStr += ")";
		} else {
			
			if (pointer -> getRight() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getRight() -> getVar();
			} else {
				userStr += pointer -> getRight() -> getVal();
			}
			userStr += ")";
			return userStr;
		}
		x = 0;
	}


	
	return userStr;

}


string Expression::print_prefix(Node* pointer) const {
	string userStr;
	int x = 1;
	
	while (x != 0){
		if ((pointer -> getLeft() -> nodeCheck() != EXPRESSION) && 
		(pointer -> getRight() -> nodeCheck()!= EXPRESSION)) {
			userStr += pointer -> getData();
			if (pointer -> getLeft() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getLeft() -> getVar();
			} else {
				userStr += pointer -> getLeft() -> getVal();
			}
			if (pointer -> getRight() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getRight() -> getVar();
			} else {
				userStr += pointer -> getRight() -> getVal();
			}
		return userStr;
		}
			
		if (pointer -> getLeft() -> nodeCheck() == EXPRESSION){
			userStr += pointer -> getData();
			pointer = pointer -> getLeft();
			userStr += Expression::print_prefix(pointer);
			pointer = pointer -> getParent();
		} else {
			userStr += pointer -> getData();
			if (pointer -> getLeft() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getLeft() -> getVar();
			} else {
				userStr += pointer -> getLeft() -> getVal();
			}
			pointer = pointer -> getRight();
			userStr += Expression::print_prefix(pointer);
			return userStr;
		}
		if (pointer -> getRight() -> nodeCheck() == EXPRESSION){
			pointer = pointer -> getRight();
			//userStr += pointer -> getData();
			userStr += Expression::print_prefix(pointer);
			pointer = pointer -> getParent();
		} else {
			if (pointer -> getRight() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getRight() -> getVar();
			} else {
				userStr += pointer -> getRight() -> getVal();
			}
			return userStr;
		}

		x = 0;
	}


	
	return userStr;

}


string Expression::print_postfix(Node*pointer) const {

	string userStr;
	int x = 1;
	
	while (x != 0){
		if ((pointer -> getLeft() -> nodeCheck() != EXPRESSION) && 
		(pointer -> getRight() -> nodeCheck()!= EXPRESSION)) {
			if (pointer -> getLeft() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getLeft() -> getVar();
			} else {
				userStr += pointer -> getLeft() -> getVal();
			}

			if (pointer -> getRight() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getRight() -> getVar();
			} else {
				userStr += pointer -> getRight() -> getVal();
			}
			userStr += pointer -> getData();
			return userStr;
		}
			
		if (pointer -> getLeft() -> nodeCheck() == EXPRESSION){
			pointer = pointer -> getLeft();
			userStr += Expression::print_postfix(pointer);
			pointer = pointer -> getParent();
			
		} else {
			if (pointer -> getLeft() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getLeft() -> getVar();
			} else {
				userStr += pointer -> getLeft() -> getVal();
			}
			pointer = pointer -> getRight();
			userStr += Expression::print_postfix(pointer);
			pointer = pointer -> getParent();
			userStr += pointer -> getData();
			return userStr;
		}
		if (pointer -> getRight() -> nodeCheck() == EXPRESSION){
			pointer = pointer -> getRight();
			userStr += Expression::print_postfix(pointer);
			pointer = pointer -> getParent();
			userStr += pointer -> getData();
		} else {
			if (pointer -> getRight() -> nodeCheck() == VARIABLE){
				userStr += pointer -> getRight() -> getVar();
			} else {
				userStr += pointer -> getRight() -> getVal();
			}
			userStr += pointer -> getData();
			return userStr;
		}

		x = 0;
	}

	return userStr;
	
}

int Expression::evaluate(string infix) {

	stack <int> operands;
	stack <char> operators;

	int num1, num2;
	int length = infix.size();

	for (int i = 0; i < length; i++){
		if (isalpha(infix[i]) == true){
			exit (EXIT_FAILURE);
		}
		if (infix[i] == '('){
			i++;
		}
		if (isdigit(infix[i])){
			operands.push(infix[i] - '0');
		}
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
			operators.push(infix[i]);
		}
		if (infix[i] == ')') {
			
			switch(operators.top()){
				case '+':
					num1 = operands.top();
					operands.pop();
					num2 = operands.top();
					operands.pop();
					operands.push(num2+num1);
					break;
				case '-':
					num1 = operands.top();
					operands.pop();
					num2 = operands.top();
					operands.pop();
					operands.push(num2-num1);
					break;
				case '*':
					num1 = operands.top();
					operands.pop();
					num2 = operands.top();
					operands.pop();
					operands.push(num2*num1);
					break;
				case '/':
					num1 = operands.top();
					operands.pop();
					num2 = operands.top();
					operands.pop();
					operands.push(num2/num1);
					break;
			}
			operators.pop();
		}
	
	}

	return operands.top();
}

char Expression::compare(int a, int b){
	if (a==b){
		return '=';
	}
	else if(a<b){
		return '<';
	}
	else if(a>b){
		return '>';
	}
	else{
		return 'not comparable';
	}
}
