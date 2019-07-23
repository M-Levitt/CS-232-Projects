#ifndef _INTEGER_ARRAY_STACK
#define _INTEGER_ARRAY_STACK

const int MAXSTACK = 10; //i.e., the maximum stack size

class IntegerArrayStack {
private:
	int items[MAXSTACK];
	int top; //index to top of stack
public:
	IntegerArrayStack(); //default constructor
	bool isEmpty() const;
	void push(const int& newEntry);
	int pop();
	int peek() const;
	void display();
};
#endif // !_INTEGER_ARRAY_STACK
