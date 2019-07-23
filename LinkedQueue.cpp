#include<iostream>
#include"LinkedQueue.h"
using namespace std;

LinkedQueue::LinkedQueue() {
	backPtr = nullptr;
	frontPtr = nullptr;
	count = 0;
}

LinkedQueue::LinkedQueue(const LinkedQueue& aQueue) { //copy constructor
	Node* origChainPtr = aQueue.frontPtr;

	if (origChainPtr == nullptr) {
		frontPtr = nullptr; //original queue is empty
		backPtr = nullptr;
	}
	else {
		//copy first node
		frontPtr = new Node();
		frontPtr->setItem(origChainPtr->getItem());

		//advance the original-chain pointer
		origChainPtr = origChainPtr->getNext();

		//copy remaining nodes
		Node* newChainPtr = frontPtr; //points to the last node in the new chain
		while (origChainPtr != nullptr) {
			//get next item from original chain
			int nextItem = origChainPtr->getItem();

			//create a new node containing the next item
			Node* newNodePtr = new Node(nextItem);

			//link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			//advance pointers
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}

		newChainPtr->setNext(nullptr); //flag end of chain
		backPtr = newChainPtr;
	}

}

LinkedQueue::~LinkedQueue() { //destructor
	if (frontPtr != nullptr) {
		Node* curPtr = frontPtr; //start with front end of queue
		while (curPtr != backPtr) {
			Node* tempPtr = curPtr->getNext();
			delete curPtr;
			curPtr = tempPtr;
			tempPtr = nullptr;
		}

		delete curPtr;  //delete the last node
		curPtr = nullptr;
		frontPtr = nullptr;
		backPtr = nullptr;
	}
}
bool LinkedQueue::isEmpty() const {
	return backPtr == nullptr;
}

bool LinkedQueue::enqueue(const int& newEntry) {
	Node* newNodePtr = new Node(newEntry);

	count += 1; //increment the number of items in our queue
	//Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; //the queue was empty
	else
		backPtr->setNext(newNodePtr); //the queue was not empty

	backPtr = newNodePtr;	//new node is at back

	return true;
}

bool LinkedQueue::dequeue() {
	bool result = false;


	if (!isEmpty()) {
		count -= 1; //decrement the number of items in our queue
		//queue is not empty, remove front
		Node* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr) {
			//special case, one node in queue
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();

		//return deleted node to system
		nodeToDeletePtr->setNext(nullptr);

		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;
	}

	return result;
}

int LinkedQueue::peekFront() const {
	if (!isEmpty())
		return frontPtr->getItem();

}

int LinkedQueue::numOfItems() const {
	return count;
}

bool LinkedQueue::clear() {
	bool result = false;
	while (dequeue() == true) {
		dequeue();
	}
	result = true;
	cout << "Queue is cleared";
	return result;
}