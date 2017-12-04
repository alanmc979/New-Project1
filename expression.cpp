#include "expression.h"
#include <string>

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


string Expression::print_prefix(Node* pointer) const {
	string userStr;
	int x = 1;
	
	while (x != 0){
		if ((pointer -> getLeft() -> nodeCheck() != EXPRESSION) && 
		(pointer -> getRight() -> nodeCheck()!= EXPRESSION)) {
		userStr += pointer -> getData();
		userStr += pointer -> getLeft() -> getVar();
		userStr += pointer -> getRight() -> getVal();
		return userStr;
		}
			
		if (pointer -> getLeft() -> nodeCheck() == EXPRESSION){
			userStr += pointer -> getData();
			pointer = pointer -> getLeft();
			userStr += Expression::print_prefix(pointer);
			pointer = pointer -> getParent();
		} else {
			userStr += pointer -> getData();
			userStr += pointer -> getLeft() -> getVar();
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
			userStr += pointer -> getRight() -> getVal();
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
		userStr += pointer -> getLeft() -> getVar();
		userStr += pointer -> getRight() -> getVal();
		userStr += pointer -> getData();
		return userStr;
		}
			
		if (pointer -> getLeft() -> nodeCheck() == EXPRESSION){
			pointer = pointer -> getLeft();
			userStr += Expression::print_postfix(pointer);
			pointer = pointer -> getParent();
			
		} else {
			userStr += pointer -> getLeft() -> getVar();
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
			userStr += pointer -> getRight() -> getVal();
			userStr += pointer -> getData();
			return userStr;
		}

		x = 0;
	}


	
	return userStr;

	
}
int Expression::eval(Node *source){
  if(source->get_operand1() == NULL && source->get_operand2() == NULL){
    return getVal(source);
  }
  node_type x;
  int x;
  int y;
  Node* n = source;
  int val = 0;
  x = source.getNodeType();
  if(x == EXPRESSION){
    if(source->get_operand1().getNodeType() == EXPRESSION){
      eval(source->get_operand1());
    }
    else if(source->get_operand2().getNodeType() == EXPRESSION){
      eval(source->get_operand2());
    }
    else{
      n = source->get_operand1();
      x = getVal(n);
      delete n;
      n = source->get_operand2();
      y = getVal(n);
      delete n;
      val = x source.print_operator() y;
      Node p = new Node(val);
      p->setParent(source->getParent());
      delete source;
      source = p;
    }
  }      
}
bool Expression::compare(int a, int b){//We need to make int a= eval(source)
return (a==b);
}








