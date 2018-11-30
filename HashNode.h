//
// Created by Alex Hayden van Zuiden-Rylander on 11/26/18.
//

#ifndef ASSIGNMENT4_HASHMAP_H
#define ASSIGNMENT4_HASHMAP_H

#include <iostream>
#include "LinkedList.h"

using namespace std;
template <typename K, typename D>
class HashNode{
    // Private data members.
    K key;
    D data;
    HashNode<K,D>* next;
public:
    HashNode(K key, D data): key(key), data(data){};
    void insert(HashNode&);
    void deleteHashValue(D*&);

    D getData() const {
        return data;
    }

    void setData(D data) {
        HashNode::data = data;
    }

    HashNode<K,D> *getNext() const {
        return next;
    }

    void setNext(HashNode<K, D> *next) {
        HashNode::next = next;
    }
};






#endif //ASSIGNMENT4_HASHMAP_H
