#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include "node.h"

using namespace std;

class Expression{
public:
	Expression();
   
	

	string print_infix(Node *pointer) const;
    string print_prefix(Node *pointer) const;
    string print_postfix(Node *pointer) const;
   	int evaluate(string infix); //implement infix with parenthesis
   	bool Expression::compare(int a, int b){

private:
	Node* pointer;
	
	





};
#endif