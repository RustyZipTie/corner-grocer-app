#include "FoodNode.h"
#include <string>
#ifndef CORNERGROCER_FOODLIST_H
#define CORNERGROCER_FOODLIST_H
using namespace std;

class FoodList {
public:
	FoodList();
	void addNode(string name);
	void read(istream& in);
	FoodNode* find(string name) const;
	void outputAll(ostream& out) const;
	void histogramAll(ostream& out) const;
	~FoodList();
private:
	FoodNode* head;
	FoodNode* tail;  
};

#endif // !CORNERGROCER_FOODLIST_H


