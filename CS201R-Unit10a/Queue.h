#pragma once
#include "LinkedList.h"

class Queue : public LinkedList {
public:
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
			cout << "The queue is empty\n";
		}
	}
};