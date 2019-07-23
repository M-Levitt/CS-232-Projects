#include<cassert>
#include<iostream>
#include"CharStack.h"
using namespace std;

CharStack::CharStack() {
	top = -1;
}

bool CharStack::isEmpty() const {
	return top < 0;
}

void CharStack::push(const char& newEntry) {
	if (top < MAXSTACK - 1) {
		top += 1;
		items[top] = newEntry;
	}
}

void CharStack::pop() {
	if (!isEmpty()) {
		top--;
	}
	else {
		cout << "Stack is empty, cannot pop." << endl;
	}
}

char CharStack::peek() const {
	assert(!isEmpty()); //enfore precondition

	return items[top];
}