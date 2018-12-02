//
// Created by Alex on 11/15/2018.
//



#include "BinarySearchTree.h"
#include "Item.h"
#include <time.h>


#include <fstream>

class BarcodeBSTScanner {
    BinarySearchTree<Item> tree;

public:

    void addItem(Item &i) {
        tree.insert(i);
    }

    void search(string key) {
        Item i;
        i.setKey(key);
        clock_t timer;
        timer = clock();
        bool found = tree.search(i);
        timer = clock() - timer;
        int ms = double(timer) / CLOCKS_PER_SEC * 1000;
        if (found) {
            cout << "BST search time: " << ms << " milliseconds." << endl;
        }
    }


};



