#include<iostream>
#include "ArrayQueue.h"
using namespace std;

ArrayQueue::ArrayQueue()
{
	front = 0;
	back = (MAX_QUEUE - 1);
	count = 0;
}

bool ArrayQueue::isEmpty() const
{
	return count == 0;
}

bool ArrayQueue::enqueue(const int& newEntry)
{
	bool result = false;
	if (count < MAX_QUEUE)
	{
		// Queue has room for another item 
		back = (back + 1) % MAX_QUEUE;
		items[back] = newEntry;
		count++;
		result = true;
	}  // end if 
	return result;
}

bool ArrayQueue::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		front = (front + 1) % MAX_QUEUE;
		count--;
		result = true;
	}
	return result;
}

int ArrayQueue::numOfItems() const {
	return count;
}

bool ArrayQueue::clear() {
	front = 0;
	back = (MAX_QUEUE - 1);
	count = 0;

	return true;
}
//int ArrayQueue::peekFront() const throw (PrecondViolatedExcep)
//{
//	// Enforce precondition 
//	if (isEmpty())
//		throw PrecondViolatedExcep("peekFront() called with empty queue");
//	// Queue is not empty; return front 
//	return items[front];
//	
//	//int temp;
//	//try {
//	//	temp = items[front];
//	//}
//	//catch (exception e) {
//	//	cout << "peekFront() called with empty queue";
//	//}
//	//return items[front];
//}

//int ArrayQueue::peekFront() const throw(logic_error) {
int ArrayQueue::peekFront() const {
	if (isEmpty()) {
		//throw logic_error("peekFront() called with empty queue");
		cout << "Queue is empty so there is nothing to peek." << endl;
		return -1;
	}
	else
		return items[front];

}

