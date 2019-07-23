#ifndef _ARRAY_QUEUE 
#define _ARRAY_QUEUE 
#include "QueueInterface.h"  
const int MAX_QUEUE = 50;

class ArrayQueue : public QueueInterface
{
private:
	int items[MAX_QUEUE];  // Array of queue items 
	int front;                // Index to front of queue 
	int back;                 // Index to back of queue 
	int count;                // Number of items currently in the queue 
public:
	ArrayQueue();
	// Copy constructor and destructor supplied by compiler 
	bool isEmpty() const;
	bool enqueue(const int& newEntry);
	bool dequeue();
	bool clear();
	/** @throw PrecondViolatedExcep if queue is empty. */
	//int peekFront()  const throw (PrecondViolatedExcep);
	//int peekFront() const throw(logic_error);
	int peekFront() const;
	int numOfItems() const;
}; // end ArrayQueue 

#endif 