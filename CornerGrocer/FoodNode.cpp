#include "FoodNode.h"
#include <iostream>
#include <iomanip>
/*
* Creates a new food with the specified name, quantity of 1, and next node is null
* @param name is the name of the new food
*/
FoodNode::FoodNode(string name) {
	this->name = name;
	this->quantity = 1;
	this->next = nullptr;
}

/*
* attatches a node after the current one
* if the current node already has a node attatched to it, 
* the attatched node will be re-attatched to the new node
* @param newNode is the new node to be attatched
*/
void FoodNode::attatch(FoodNode* newNode) {

	// hold attatched node temporarily
	FoodNode* temp = this->next;

	// attatch new node to this node
	this->next = newNode;

	// attatch previously attatched node to the newly attatched node
	newNode->next = temp;
}

/*
* returns the name of this food
*/
string FoodNode::getName() const {
	return this->name;
}

/*
* returns the quantity of this food
*/
int FoodNode::getQuantity() const {
	return this->quantity;
}

/*
* increments the quantity of this food
*/
void FoodNode::increment() {
	this->quantity++;
}

/*
* outputs food in (| name | quantity |) format
* output is usually 27 chars wide, unless name or quantity are unreasonably large
* @param out is the ostream to write the data to
*/
void FoodNode::output(ostream& out) const{
	out << "| " << setw(15) << right << name << " | ";
	out << setw(5) << left << quantity << " |" << endl;
}

/*
* outputs food in histogram format
* i.e. for name="apples" and quantity=5:
*         apples|*****
* @param out is the ostream to write the data to
*/
void FoodNode::histogram(ostream& out) const {
	out << setw(15) << right << name << "|";
	for (int i = 0; i < quantity; i++) {
		out << "*";
	}
	out << endl;
}

FoodNode* FoodNode::getNext() const {
	return this->next;
}

/*
* deletes this node and all nodes after it
*/
FoodNode::~FoodNode() {
	delete this->next;
}
