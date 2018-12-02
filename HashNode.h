//
// Created by Alex Hayden van Zuiden-Rylander on 11/26/18.
//

#ifndef ASSIGNMENT4_HASHMAP_H
#define ASSIGNMENT4_HASHMAP_H

#include <iostream>
#include "LinkedList.h"


using namespace std;


struct hNode {

    string key;
    string data;
public:
    hNode(string key, string data) : key(key), data(data) {};


    string getKey() const {
        return key;
    }

    void setKey(string &k) {
        this->key.assign(k);
    }

    const string &getData() const {
        return data;
    }

    void setData(const string &data) {
        hNode::data = data;
    }

    friend ostream &operator<<(ostream &os, hNode &hn) {

        os << "UPC Code: " << hn.key << "\n" << "Item Info: " << hn.data << endl;
        return os;
    }

    bool operator==(const hNode &rhs) const {
        return key == rhs.key;
    }

    bool operator!=(const hNode &rhs) const {
        return !(rhs == *this);
    }

    void operator=(hNode h) {
        key = h.key;
        data = h.data;
    }


};


//class HashNode{
//
//    hNode hashNode;
//
//
//public:
//    const hNode &getHashNode() const {
//        return hashNode;
//    }
//
//    void setHashNode(const hNode &hashNode) {
//        HashNode::hashNode = hashNode;
//    }
//
//};
//template <typename K, typename D>
//class HashNode{
//    // Private data members.
//    K key;
//    D data;
//    HashNode<K,D>* next;
//public:
//    HashNode(K key, D data): key(key), data(data){};
////    void insert(HashNode&);
////    void deleteHashValue(D*&);
//
//    D getData() const {
//        return data;
//    }
//
//    void setData(D data) {
//        HashNode::data = data;
//    }
//
//    HashNode<K,D> *getNext() const {
//        return next;
//    }
//
//    void setNext(HashNode<K, D> *next) {
//        HashNode::next = next;
//    }
//
//    friend ostream& operator<<(ostream &os,HashNode& hn){
//
//        os << "UPC Code: " << hn.key << "\n" << "Item Info: " << hn.data << endl;
//        return os;
//    }
//
//    bool operator==(HashNode hn){
//        return key = hn.key;
//    }
//
//    K getKey() const {
//        return key;
//    }
//
//    void setKey(K key) {
//        HashNode::key = key;
//    }
//};

//array of linked list of hash nodes




#endif //ASSIGNMENT4_HASHMAP_H
