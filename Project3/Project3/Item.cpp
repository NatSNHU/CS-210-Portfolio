#include<string>
#include<iostream>
#include <iomanip>
using namespace std;
#include "Item.h"

Item::Item(string itemName, int count) {
	this->itemName = itemName;
	this->count = count;
}
string Item::GetName() {
	return itemName;
}
int Item::GetCount() {
	return count;
}
Item* Item::GetNext() {
	return nextNodePtr;
}
void Item::AddOne() {
	this->count++;
}
void Item::InsertAfter(Item* nodeLoc) {
	Item* tmpNext = nullptr;
	tmpNext = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tmpNext;
}
void Item::PrintCount() {
	cout << itemName << " " << count << endl;
}
void Item::PrintCountHist() {
	cout << std::right << std::setw(13) << itemName;
	for (int i = 1;i <= count;i++) cout << std::left << " [-]";
	cout << endl;
}