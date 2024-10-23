#include "LinkedList.h"

LinkedList::LinkedList() {
	cout << "CONSTRUCTOR\n";
	headPtr = nullptr;
	tailPtr = nullptr;
}
LinkedList::LinkedList(dataType d) {
	cout << "CONSTRUCTOR\n";
	Node* tempPtr = new Node;
	tempPtr->data = d;
	tempPtr->nextPtr = nullptr;
	headPtr = tempPtr;
	tailPtr = tempPtr;
}
LinkedList::~LinkedList() {
	
	cout << "DESTRUCTOR\n";
}
void LinkedList::addNode(dataType d) {
	//create a new node with data d
	Node* tempPtr = new Node;
	tempPtr->data = d;
	tempPtr->nextPtr = nullptr;
	//add the node to the end of the list
	if (headPtr == nullptr) {
		headPtr = tempPtr;
		tailPtr = tempPtr;
	}
	else {
		tailPtr->nextPtr = tempPtr;
		tailPtr = tempPtr;
	}
}
// Adds a node to the list in ascending order based on the age field
void LinkedList::addNodeOrdered(dataType d) {
	Node* tempNode = new Node;
	tempNode->data = d;
	tempNode->nextPtr = nullptr;

	// If the list is empty, set the new node as both head and tail
	if (headPtr == nullptr) {
		headPtr = tempNode;
		tailPtr = tempNode;
		return;
	}

	// If the new node should be placed before the head
	if (headPtr->data.age >= tempNode->data.age) {
		tempNode->nextPtr = headPtr;
		headPtr = tempNode;
		return;
	}

	// Traverse the list to find the correct position for the new node
	Node* currPtr = headPtr;
	while (currPtr->nextPtr != nullptr && currPtr->nextPtr->data.age < tempNode->data.age) {
		currPtr = currPtr->nextPtr;
	}

	// Insert the new node in its correct position
	tempNode->nextPtr = currPtr->nextPtr;
	currPtr->nextPtr = tempNode;

	// Update the tail pointer if the new node is added at the end
	if (currPtr == tailPtr) {
		tailPtr = tempNode;
	}
}

void LinkedList::delNode(string name) {
	//delete a node with the name
	//if the node is not in the list, print an error message
	//if the node is in the list, delete the node
	//if the node is the head, update the head
	//if the node is the tail, update the tail
	//if the node is in the middle, update the pointers	
	Node* tempPtr = headPtr;
	if (tempPtr != nullptr) {
		if (tempPtr->data.lname == name) {
			headPtr = headPtr->nextPtr;
			delete tempPtr;
			tempPtr = nullptr;
		}
		while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) {
			if (tempPtr->nextPtr->data.lname == name) {
				Node* deletePtr = tempPtr->nextPtr;
				tempPtr->nextPtr = deletePtr->nextPtr;
				delete deletePtr;
				deletePtr = nullptr;
				if (tempPtr->nextPtr == nullptr) {
					tailPtr = tempPtr;
				}
			}
			else {
				tempPtr = tempPtr->nextPtr;
			}
		}
	}

}
void LinkedList::printList() {
	//cout << "need to implement printlist\n";
	Node* tempPtr = headPtr;
	while (tempPtr != nullptr) {
		cout << tempPtr->data.fname << " " << tempPtr->data.lname << " " << tempPtr->data.age << endl;
		tempPtr = tempPtr->nextPtr;
	}
	cout << endl << endl;
}