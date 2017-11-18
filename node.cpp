#include "node.h"
#include <string>


Node::Node (char var, node_type myNode){

	this -> data.var = var;
	this -> node_t = myNode;
}

Node:: Node(operator_type op, Node* operand1, Node* operand2, Node* parent){
	this -> data.op = op;
	this -> operand1 = operand1;
	this -> operand2 = operand2;
	this -> parent = parent;
}

Node::Node(int val, node_type myNode){
	this -> data.val = val;
	this -> node_t = myNode;
}


Node::~Node(){
	delete operand1;
	delete operand2;
}

void Node::setData(char operate){
	operator_type myOP;
	if (operate == '+'){
		myOP = PLUS;
	}
	if (operate == '-'){
		myOP = MINUS;
	}
	if (operate == '*'){
		myOP = MULT;
	}
	if (operate == '/'){
		myOP = DIVIDE;
	}
	this -> data.op = myOP;
}

void Node::Left(Node* n){
	this -> operand1 = n;
}

void Node::Right(Node* n){
	this -> operand2 = n;
}

char Node::getData(){
	operator_type oper = this->data.op;
	char myOP;
	if (oper == PLUS){
		myOP = '+';
	}
	if (oper == MINUS){
		myOP = '-';
	}
	if (oper == MULT){
		myOP = '*';
	}
	if (oper == DIVIDE){
		myOP = '/';
	}
	if (oper == NONE){
		myOP = '\0';
	}
	return myOP;
}

Node* Node::getLeft(){
	return this->operand1;
}

Node* Node::getRight(){
	return this->operand2;
}

Node* Node::getParent(){
	return this -> parent;

}
char Node::getVal(){
	int x = this -> data.val;
	char y = '0' + x;
	return y;
}


char Node::getVar(){
	//return 'x';
	return this -> data.var;
}

node_type Node::nodeCheck (){


	if (node_t == VARIABLE){ //if point is pointing to node var
		return VARIABLE;
	}

	if (node_t == INTEGER){ //if point is pointing to a node val
		return INTEGER;
	}
	return EXPRESSION;
}
node_type Node::typeCheck (char x){
	if (x >= 'a' && x <= 'z'){
		return VARIABLE;
	}
	if (x >= '0' && x <= '9'){
		return INTEGER;
	}

	return EXPRESSION;
}

bool Node::ifData(char x){
	if (x == '+' || x == '-' || x == '*' || x == '/'){
		return true;
	}
	return false;
}


