#ifndef _CHAR_STACK
#define _CHAR_STACK

const int MAXSTACK = 100;

class CharStack {
private:
	char items[MAXSTACK];
	int top; //index to the top of the stack
public:
	CharStack(); //default constructor
	bool isEmpty() const;
	void push(const char& newEntry);
	void pop();
	char peek() const;
};

#endif // !_CHAR_STACK
