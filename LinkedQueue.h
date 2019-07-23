#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "QueueInterface.h"
#include "Node.h"

class LinkedQueue : public QueueInterface {
private:
	Node* backPtr;
	Node* frontPtr;
	int count; //number of items currenlty in the queue
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& aQueue);
	~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const int& newEntry);
	bool dequeue();
	int peekFront() const;

	bool clear();
	int numOfItems() const;
};

#endif