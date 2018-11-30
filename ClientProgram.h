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
    ll actualKey;
    BarcodeBSTScanner bst;
    BarcodeArrayScanner arr;
    HashMap hm;
    //HashNode<ll,string> hn;
    //array<LinkedList<HashNode<ll,string>>,1301> * hashTable = new array<LinkedList<HashNode<ll,string>>,1301>;
    //LinkedList<HashNode<ll,string>> hash[1000];
    //conversion from string to long long
    ll STLL(string s) {
        ll int num = 0;
        ll po = 1;
        for (ll i = s.length() - 1; i >= 0; i--) {

            num += po * (s[i] - 48);
            cout << num <<endl;
            po *= 10;
        }
       // cout << "returning num " <<num <<endl;
        return num;
    }

public:
    void generateBracodeData() {

        ifstream bc;
        //this will need to be the path where it will be stored in your file system
        bc.open("/Users/alex/Downloads/BarcodeInfo.txt");
        if (!bc) {
            cerr << "Unable to open the file." << endl;
        }
        //the first line is useless and not matching our data set so we skip it with this statement
        getline(bc, line);
        //iterate through the file so that you can read all the data
        int index = 0;
        while (bc.good() && bc.is_open()) {
            try {
            //    cin.clear();

                getline(bc, line);

                stringstream ss(line);
                //getting the string key
                getline(ss, key, ',');
                //making it a long long
                //stringstream(key) >> actualKey;
                actualKey = STLL(key);
                //grabing the string of item information or "data"
                getline(ss, data, ',');
                //using a temporary item to store the values
                Item temp(actualKey, data);
                cout << actualKey << endl;
                hNode hn(actualKey, data);
                //insert the item into the binary search tree
                bst.addItem(temp);
                //inserting the item into an item array
                arr.addArrItem(temp);

               // ll in = hm.generateHashNum(actualKey,1301);
                hm.insert(hn);

            } catch (bad_cast&){

            }
        }
        //close the file, don't want to leave it open

        bc.close();
//        cout << hashTable->at(16) << endl;
      searchKey();
    }

    void searchKey() {
        ll k;

        //prompting the client for a upc code to search
        cout << "UPC Code: ";
        cin >> k;
        //searching both the binary tree and array
        bst.search(k);
        arr.search(k);
        hm.search(k);


    }
private:

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
