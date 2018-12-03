//
// Created by Alex on 11/20/2018.
//

#ifndef ASSIGNMENT4_ITEM_H
#define ASSIGNMENT4_ITEM_H

#include <iostream>
//#include <map>
#include <sstream>
//#include <stdio.h>


#include <fstream>
using namespace std;
class Item{
    string key;
    string data;
public:
    Item() = default;
    Item(string _key, string _data) : key(_key), data(_data){}

    string getKey() const {
        return key;
    }

    void setKey(string key) {
        Item::key = key;
    }

    const string &getData() const {
        return data;
    }

    void setData(const string &data) {
        Item::data = data;
    }
    void operator=(const Item& i){
        key = i.key;
        data = i.data;
    }
    bool operator<(Item& i){
            return i.key < key;
    }
    bool operator>(Item& i){
            return i.key > key;
    }
    friend ostream& operator<<(ostream &os,Item& i){
        os << "UPC Code: " << i.key << "\n" << "Item Info: " << i.data << endl;
        return os;
    }

};

#endif //ASSIGNMENT4_ITEM_H
