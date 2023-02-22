/*
 * CornerGrocer.cpp
 *
 *  Date: 2/16/2023
 *  Author: Nathan H.
 */

#include <iostream>
#include <fstream>
#include <map>
#include "Item.h"
#include <string>

using namespace std;

Item* lastNode = nullptr;
Item* headNode = nullptr;
map<string, Item*> itemCount;

void printMenu() { //print menu
	cout << "1. Search Item\n2. Print List\n3. Print Histogram\n4. Exit\n" << endl;
}

void searchItem() { //search item from search term
	string search = "";
	cout << "Enter item to search: " << endl;
	cin >> search;
	if (itemCount.count(search) != 0) {
		(*itemCount.at(search)).PrintCount();
		cout << "\n" << endl;
	}
	else
		cout << "No sales for specified item\n" << endl;
}

void printHistogram() { //print catalog histgram
	Item* curNode = headNode;
	while (curNode != nullptr) {
		(*curNode).PrintCountHist();
		curNode = (*curNode).GetNext();
	}
	cout << "\n" << endl;
}

void printFreqList() { //print catalog
	Item* curNode = headNode;
	while (curNode != nullptr) {
		(*curNode).PrintCount();
		curNode = (*curNode).GetNext();
	}
	cout << "\n" << endl;
}

void setFreqList(string path) { //generate catalog
	string inName = "";
	ifstream inFS;
	ofstream outfs("frequency.dat"); //Create output file
	inFS.open(path); //Open ref file

	while (!inFS.eof()) {
		inFS >> inName; //read next line

		if (itemCount.count(inName) == 0) {//if new item name
			itemCount.emplace(inName, new Item(inName, 0));//make new item

			if (lastNode != nullptr) { //if it isn't the first item in the list
				(*lastNode).InsertAfter(itemCount[inName]); //link list items
			}
			else {
				headNode = itemCount[inName]; // set head node
			}
			lastNode = itemCount[inName];//set last node
		}
		(*itemCount[inName]).AddOne();//increase item count
	}

	//set dat file
	Item* curNode = headNode;
	while (curNode != nullptr) {
		outfs << (*curNode).GetName() << " " << (*curNode).GetCount() << endl;
		curNode = (*curNode).GetNext();
	}
	inFS.close();
	outfs.close();
}

int main() {
	setFreqList("CS210_Project_Three_Input_File.txt");

	int userSelection = 0;

	while (userSelection != 4) {
		printMenu();
		cin >> userSelection;
		if (cin.fail()) {  //validate input
			cin.clear();
			string dump = "";
			getline(cin,dump);
			cout << dump << " IS INVALID INPUT" << endl;
		}

		cout << "\n" << endl;
		switch (userSelection) { //run function from selection
		case 1:
			searchItem();
			break;
		case 2:
			printFreqList();
			break;
		case 3:
			printHistogram();
			break;
		}
	}
	return 0;
}