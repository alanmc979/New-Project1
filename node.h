#ifndef NODE_H
#define NODE_H
//#include <string>

enum node_type{EXPRESSION, VARIABLE, INTEGER};
enum operator_type{PLUS, MINUS, MULT, DIVIDE, NONE};

union data_type {
    operator_type op;
    char var;
    int val;
};

class Node {
	public:
		// Constructor
        Node(char var = 'x', node_type = VARIABLE);
        Node(operator_type op = PLUS, Node* operand1 = 0, Node* operand2 = 0, Node* parent = 0);
        Node(int val = 0, node_type myNode = INTEGER);
        // Destructor
        ~Node();

        
        void setData(char operate);
        void Left(Node* n);
        void Right(Node* n);
        
        char getData();
        Node *getLeft();
        Node *getRight();
        Node *getParent();
        char getVal();
        char getVar();
        
        node_type nodeCheck();
        node_type typeCheck(char x);
        bool ifData(char x);

    private:
        node_type node_t;
        data_type data;
       
        char operate;

        
        Node* operand1;
        Node* operand2;
        Node* parent;

};

#endif