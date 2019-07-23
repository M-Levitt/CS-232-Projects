//*****************************************************************
//  HashTable.h
//  HashTable
//
//  Created by Karlina Beringer on June 18, 2014.
//
//  This header file contains the Hash Table class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

//*****************************************************************
// Hash Table objects store a fixed number of Linked Lists.
//*****************************************************************
class HashTable
{
private:
	LinkedList * array; // Array is a reference to an array of Linked Lists.
	int length; // Length is the size of the Hash Table array.
	int hash(string itemKey); // Returns an array location for a given item key.

public:
	HashTable(int tableLength = 13); // Constructs the empty Hash Table object. Array length is set to 13 by default.
	void insertItem(Item * newItem); // Adds an item to the Hash Table.
	bool removeItem(string itemKey); // Deletes an Item by key from the Hash Table. Returns true if the operation is successful.
	Item * getItemByKey(string itemKey);// Returns an item from the Hash Table by key. If the item isn't found, a null pointer is returned.
	void printTable();// Display the contents of the Hash Table to console window.
	void printHistogram();// Prints a histogram illustrating the Item distribution.
	int getLength();// Returns the number of locations in the Hash Table.
	int getNumberOfItems(); // Returns the number of Items in the Hash Table.
	~HashTable(); // De-allocates all memory used for the Hash Table.
};

#endif