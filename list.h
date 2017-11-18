#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <string>
using namespace std;

class list {
public:
	list(string expression);

	Node* linkedlist();


private:
	string expression;
	char *array;
	Node* current;
	char *cursor;


};

#endif
