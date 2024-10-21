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
	
	cout << "need to implement addnode\n";
}
void LinkedList::addNodeOrdered(dataType d) {
	cout << "need to implement addnode ordered\n";
}
void LinkedList::delNode(string name) {
	//delete a node with the name
	//if the node is not in the list, print an error message
	//if the node is in the list, delete the node
	//if the node is the head, update the head
	//if the node is the tail, update the tail
	//if the node is in the middle, update the pointers
	
	cout << "need to implement delnode\n";
}
void LinkedList::printList() {
	cout << "need to implement printlist\n";

}