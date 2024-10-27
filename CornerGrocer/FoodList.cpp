#include "FoodList.h"
#include <iostream>

/*
* creates an empty list
*/
FoodList::FoodList() {
	this->head = nullptr;
	this->tail = nullptr;
}

/*
* creates a new node, then attatches to the end of the list
* (i.e. the new node becomes the tail)
* @param name is the name of the new food node
*/
void FoodList::addNode(string name) {
	// make a new node
	FoodNode* newNode = new FoodNode(name);

	// if list is empty, make new node the head and tail
	if (this->head == nullptr) {
		this->head = newNode;
		this->tail = this->head;
	}
	// otherwise, attatch to the end
	else {
		this->tail->attatch(newNode);
		this->tail = newNode;
	}
}

/*
* reads data from input file
* @param in is an ifstream associated with the file to be read from
*/
void FoodList::read(istream& in) {
	FoodNode* match = nullptr;
	string temp;

	// loop over every line in the file
	while (! in.eof()) {
		// read line
		in >> temp;

		// try to find match
		match = this->find(temp);

		// if found, increment quantity
		// else, create new node
		if (match) {
			match->increment();
		}
		else {
			this->addNode(temp);
		}
	}
}

/*
* finds and returns the first node that's name matches the name parameter
* returns nullptr if name not found
* @parameter name is the name to search for
*/
FoodNode* FoodList::find(string name) const {
	// start at the head
	FoodNode* currNode = this->head;

	// search until match is found or end of list is reached
	while (currNode != nullptr) {
		if (currNode->getName() == name) {
			return currNode;
		}
		currNode = currNode->getNext();
	}

	// if no match found, return nullptr
	return nullptr;
}

/*
* outputs a table of all nodes
* @param out is the ostream to write to
*/
void FoodList::outputAll(ostream& out) const {
	// print header
	out << "+-------------------------+" << endl;
	out << "|            name | qty   |" << endl;
	out << "|-------------------------|" << endl;

	// print each line
	FoodNode* currNode = this->head;
	while (currNode != nullptr) {
		currNode->output(out);
		currNode = currNode->getNext();
	}

	// print bottom
	out << "+-------------------------+" << endl;
}

/*
* prints a histogram of all nodes
* @param out is the ostream to write to
*/
void FoodList::histogramAll(ostream& out) const {
	// print histogram for each node
	FoodNode* currNode = this->head;
	while (currNode != nullptr) {
		currNode->histogram(out);
		currNode = currNode->getNext();
	}
}

/*
* Deletes all nodes
*/
FoodList::~FoodList() {
	delete this->head;
}
