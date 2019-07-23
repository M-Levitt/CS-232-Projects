#include<iostream>
using namespace std;
#include"IntegerArrayStack.h"

IntegerArrayStack::IntegerArrayStack() {
	top = -1;
}

bool IntegerArrayStack::isEmpty() const {
	return top < 0;
}

void IntegerArrayStack::push(const int& newEntry) {
	if (top < MAXSTACK - 1) { //does stack have room for newEntry
		top += 1;
		items[top] = newEntry;
	}
}

int IntegerArrayStack::pop() {
	int poppedItem = 0;
	if (!isEmpty()) {
		poppedItem = items[top];
		top -= 1;
		return poppedItem;
	}
	else {
		cout << "Stack is empty, cannot pop";
	}
	return -1;
}

int IntegerArrayStack::peek() const {
	if (!isEmpty()) {
		return items[top];
	}
	else {
		cout << "Stack is empty, cannot peek";

	}
	return -1;
}

void IntegerArrayStack::display() {
	if (top < 0) {
		cout << "No elements to display." << endl;
	}

	for (int i = 0; i <= top; i++)
	{
		cout << items[i] << " ";
	}
	cout << endl;
}