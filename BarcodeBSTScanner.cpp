//
// Created by Alex on 11/15/2018.
//



#include "BinarySearchTree.h"
#include "Item.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <time.h>
#define ll long long

#include <fstream>

class BarcodeBSTScanner {
BinarySearchTree<Item> tree;

public:

void addItem(Item& i){
tree.insert(i);
}

void search(ll key){
Item i;
i.setKey(key);
clock_t timer;
timer = clock();
tree.search(i);
timer = clock() - timer;
cout << "BST time: " << timer << " milliseconds." <<endl;
}


};



