#pragma once
#include "LinkedList.h"

class Stack : public LinkedList {
public:
	//add node
	void addNode(dataType d) {
		Node* newNode = new Node;
		newNode->data = d;
		newNode->nextPtr = nullptr;
		if (headPtr == nullptr) {
			headPtr = newNode;
			tailPtr = newNode;
		}
		else {
			newNode->nextPtr = headPtr;
			headPtr = newNode;
		}
	}

	//del Node
	void delNode() {
		if (headPtr != nullptr) {
			Node* delNode = headPtr;
			headPtr = headPtr->nextPtr;
			delete delNode;
			delNode = nullptr;
			if (headPtr == nullptr) {
				tailPtr = nullptr;
			}
		}
		else {
			cout << "The stack is empty\n";
		}
	}
};