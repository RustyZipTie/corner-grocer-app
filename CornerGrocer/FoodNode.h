#include <string>
#ifndef CORNERGROCER_FOODNODE_H
#define CORNERGROCER_FOODNODE_H
using namespace std;

class FoodNode {
public:
	FoodNode(string name);
	void attatch(FoodNode* newNode);
	string getName() const;
	int getQuantity() const;
	void increment();
	void output(ostream& out) const;
	void histogram(ostream& out) const;
	FoodNode* getNext() const;
	~FoodNode();
private:
	string name;
	int quantity;
	FoodNode* next;
};

#endif // !CORNERGROCER_FOODNODE_H



