//
// Created by Alex on 11/20/2018.
//

#ifndef ASSIGNMENT4_CLIENTPROGRAM_H
#define ASSIGNMENT4_CLIENTPROGRAM_H

#include "BinarySearchTree.h"
#include "BarcodeBSTScanner.cpp"
#include "BarcodeArrayScanner.cpp"
#include "Item.h"
#include <iostream>
#include <array>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include "HashMap.cpp"


class ClientProgram {

    string key, data, line;
    BarcodeBSTScanner bst;
    BarcodeArrayScanner arr;
    HashMap hm;
//    string *upc = new string[10000000];

public:
    void generateBracodeData() {
        int change = 1;
        ifstream bc;
        //this will need to be the path where it will be stored in your file system
        bc.open("/Users/alex/Downloads/BarcodeInfo.txt");
        if (!bc) {
            cerr << "Unable to open the file." << endl;
        }
        //the first line is useless and not matching our data set so we skip it with this statement
        getline(bc, line);
        //iterate through the file so that you can read all the data
//       int index = 0;
        while (bc.good() && bc.is_open()) {
                //grab the first line of data
                getline(bc, line);

                stringstream ss(line);
                //getting the string key
                getline(ss, key, ',');
                //grabing the string of item information or "data"
                getline(ss, data, ',');
                //using a temporary item to store the values
                Item temp(key, data);
                // cout << actualKey << endl;
                hNode hn(key, data);
                //insert the item into the binary search tree
                bst.addItem(temp);
                //inserting the item into an item array
                arr.addArrItem(temp);
                //inserting the hash node into the hash map
                hm.insert(hn);
//                upc[index] = key;
//                index++;



        }
        //close the file, don't want to leave it open
        bc.close();
    }

    void searchKey() {
        string k;

        //prompting the client for a upc code to search
        cout << "UPC Code: ";
        cin >> k;
        //searching both the binary tree and array
        bst.search(k);
        arr.search(k);
        hm.search(k);


    }

//    int generateNumbers(){
//
//        return rand()%1000000;
//    }
//
//    void gatherSearchData(){
//        string *search = new string[1001];
//        for(int i = 0; i<1000; i++){
//            search[i]= upc[generateNumbers()];
//            bst.search(search[i]);
//            arr.search(search[i]);
//              hm.search(search[i]);
//        }
//    }
};

#endif //ASSIGNMENT4_CLIENTPROGRAM_H
