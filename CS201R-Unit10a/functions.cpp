#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "functions.h"
using namespace std;

void readFile(ifstream& inFile, LinkedList& L) {
    dataType tempPerson;
    string inStr, tempStr;
    vector <string> row;

    //read data file & add to linked list
    while (getline(inFile, inStr)) {
        stringstream inSS(inStr);
        row.clear();
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }
        tempPerson.type = row[0][0];
        tempPerson.lname = row[1];
        tempPerson.fname = row[2];
        try {
            tempPerson.age = stoi(row[3]);
            L.addNode(tempPerson);
            //L.addNodeOrdered(tempPerson);
        }
        catch (logic_error) {
            cout << "error in input" << endl;
            continue;
        }
    }
}

void exampleList() {
    cout << "\nExample of Implementing a List: exampleList\n";
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Error opening files";
        return;
    }

    LinkedList list1;

    readFile(inFile, list1);
    list1.printList();

    //delete nodes from list1
    list1.delNode("Kenobi");
    list1.delNode("Bunny");
    list1.delNode("Griffin");

    //print list1 - check output
    list1.printList();

    inFile.close();
}

void exampleOrdered () {
    cout << "\nExample of Implementing an Ordered List: exampleOrdered\n";
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Error opening files";
        return;
    }
 
    LinkedList list2;
    readFile(inFile, list2);

    //delete nodes from list2
    list2.delNode("Kenobi");
    list2.delNode("Bunny");
    list2.delNode("Sullivan");
    list2.delNode("Wazowski");

    //print list2 - check output
    list2.printList();

    inFile.close();
}

void exampleStack() {
    cout << "\nExample of Implementing a Stack: exampleStack\n";
    cout << "CODE STACK DERIVED CLASS\n\n";

    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Error opening files";
        return;
    }
    
    Stack stack1;
    readFile(inFile, stack1);
    stack1.delNode();
    stack1.delNode();
    stack1.delNode();
    stack1.printList();
    
    inFile.close();
}

void exampleQueue() {
    cout << "\nExample of Implementing a Queue: exampleQueue\n";
    cout << "CODE QUEUE DERIVED CLASS\n\n";
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Error opening files";
        return;
    }
    
    Queue queue1;
    readFile(inFile, queue1);
    queue1.delNode();
    queue1.delNode();
    queue1.delNode();
    queue1.printList();
    
    inFile.close();
}