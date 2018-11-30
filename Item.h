//
// Created by Alex on 11/20/2018.
//

#ifndef ASSIGNMENT4_ITEM_H
#define ASSIGNMENT4_ITEM_H

#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#define ll long long

#include <fstream>
using namespace std;
class Item{
    ll key = 0;
    string data;
public:
    Item(){};
    Item(long long _key, string _data) : key(_key), data(_data){}

    long long int getKey() const {
        return key;
    }

    void setKey(long long key) {
        Item::key = key;
    }

    const string &getData() const {
        return data;
    }

    void setData(const string &data) {
        Item::data = data;
    }
    void operator=(Item& i){
        key = i.key;
        data = i.data;
    }
    bool operator<(Item& i){
        if(i.key < this->key) {
            return true;
        }
        return false;
    }
    bool operator>(Item& i){
        if(i.key > this->key) {
            return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream &os,Item& i){
        os << "UPC Code: " << i.key << "\n" << "Item Info: " << i.data << endl;
        return os;
    }

};

#endif //ASSIGNMENT4_ITEM_H
