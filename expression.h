#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <stack>
#include "node.h"

using namespace std;

class Expression{
public:
	Expression();
   
	

	string print_infix(Node *pointer) const;
    string print_prefix(Node *pointer) const;
    string print_postfix(Node *pointer) const;
   	int evaluate(Node* pointer); 
   	char compare(int a, int b);

private:
	Node* pointer;
	stack <int> operands;
	stack <char> operators;
	





};
#endif