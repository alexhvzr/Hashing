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
#include <sstream>
#include <stdio.h>
#include <fstream>

#define ll long long

class ClientProgram {

    string key, data, line;
    ll actualKey;
    BarcodeBSTScanner bst;
    BarcodeArrayScanner arr;

    //conversion from string to long long
    ll STLL(string s) {
        ll num = 0;
        ll po = 1;
        for (int i = s.length() - 1; i >= 0; i--) {

            num += po * (s[i] - 48);

            po *= 10;
        }
        return num;
    }

public:
    void generateBracodeData() {
        ifstream bc;
        //this will need to be the path where it will be stored in your file system
        bc.open("C:\\Users\\Alex\\GitHub\\CS300\\Assignment4\\test.txt");
        if (!bc) {
            cerr << "Unable to open the file." << endl;
        }
        //the first line is useless and not matching our data set so we skip it with this statement
        getline(bc, line);
        //iterate through the file so that you can read all the data
        while (bc.good() && bc.is_open()) {

            cin.clear();

            getline(bc, line);

            stringstream ss(line);
            //getting the string key
            getline(ss, key, ',');
            //making it a long long
            actualKey = STLL(key);
            //grabing the string of item information or "data"
            getline(ss, data, ',');
            //using a temporary item to store the values
            Item temp(actualKey, data);
            //insert the item into the binary search tree
            bst.addItem(temp);
            //inserting the item into an item array
            arr.addArrItem(temp);

        }
        //close the file, don't want to leave it open
        bc.close();
    }

    void searchKey() {
        ll k;
        //prompting the client for a upc code to search
        cout << "UPC Code: ";
        cin >> k;
        //searching both the binary tree and array
        bst.search(k);
        arr.search(k);
    }

//    void gatherSearchData(){
//        ll* llArr = new ll[100];
//        llArr = arr.generateKeys();
//        for(int i = 0; i<100; i++){
//            ll t = llArr[i];
//            bst.search(t);
//            arr.search(t);
//        }
//    }
};

#endif //ASSIGNMENT4_CLIENTPROGRAM_H
