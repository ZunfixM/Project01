// Node.cpp
// Trevor Dine
// COSC 2030
// 26 October 2018
// Project 01
// This Node file came from Lab 02 provided as a starting block and edited slightly by myself.
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods


#include "Node.h"


Node::Node(BigFloat entry)
	: entry_(entry), next_(NULL)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
	//	" ) created at " << this << endl;
}

Node::Node(BigFloat entry, Node * next)
	: entry_(entry), next_(next)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
	//	" ) created at " << this << endl;
}

Node::~Node()
{
	//cout << "Node( " << entry_ << ", " << next_ <<
	//	" ) at " << this << " destroyed" << endl;
}
