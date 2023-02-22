#include <string>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
	public:
		Item(string itemName, int count);
		string GetName();
		int GetCount();
		Item* GetNext();
		void AddOne();
		void InsertAfter(Item* nodeLoc);
		void PrintCount();
		void PrintCountHist();
	private:
		string itemName;
		int count;
		Item* nextNodePtr = nullptr;
};
#endif