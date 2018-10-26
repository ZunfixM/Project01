// LinkedList.h
// Trevor Dine
// COSC 2030
// 26 October 2018
// Project 01
// This Linked List file came from Lab 02 provided as a starting block and edited by myself.

// tom bailey   0740  5 oct 2010
// Declaration of the List class.

// A List stores and manages a sequence of doubles.

// This version uses a pointer to the first Node of a
//   singly linked list of Nodes.


#ifndef _LINKED_LIST_REG_H_
#define _LINKED_LIST_REG_H_

#include "BigFloat.h"
#include <iostream>
using std::ostream;

#include "Node.h"

#define ulong unsigned long


class List
{
public:
	//*** Standard functions ***

	// Default constructor
	// post: this List is empty.
	List();

	// Copy constructor
	// post: this List now stores a copy of the sequence stored
	//         in other
	List(const List & other);

	// Destructor
	// post: all the Nodes of this List have been destroyed.
	~List();

	// Assignment operator
	// post: this List now stores a copy of the sequence stored
	//         in other
	const List & operator=(const List & other);

	// Test for equality
	//bool operator==(const List &rhs);

	//*** Accessors ***

	// post: true has been returned just if this List is
	//         empty.
	bool empty() const;

	// post: the doubles in this List have been written to
	//         outfile.
	void print(ostream & outfile) const;

	// Finds the number of elements in the linked list.
	float size();

	// Finds the sum of all elements present in the current list utilizing big floats
	BigFloat sum();

	// Inserts the given value at the end of the list.
	void insertAtLast(BigFloat x);

	//*** Mutators ***

	// post: x has been added as the first double in this
	//         List.
	void insertAsFirst(BigFloat x);

	// pre:  this List is not empty.
	// post: the first double in this List has been removed
	//         from this List and has been returned.
	BigFloat removeFirst();

	// Finds the maximum value in the current list
	BigFloat findMax();

	// Finds the minimum value in the current list
	BigFloat findMin();

	// Copys the list into the new given list and deletes the contents of the old one.
	void copyDeleteList(List & newList);

private:
	//*** Inaccessible standard functions ***


	//*** Helper functions ***
	// process part of the linked structure

	// post: a pointer to a copy of the linked structure
	//         targeted by ptr has been returned.
	static Node * clone(Node * ptr);


private:
	Node * first_;

};


//*** Auxiliary functions ***

// post: the doubles in list have been written to outfile
ostream & operator<<(ostream & outfile, const List & list);

#endif