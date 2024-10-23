#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;


void readFile(ifstream&,LinkedList&);
void exampleList();
void exampleOrdered();
void exampleStack();
void exampleQueue();
