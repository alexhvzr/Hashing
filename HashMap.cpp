//
// Created by Alex Hayden van Zuiden-Rylander on 11/29/18.
//

#include "HashNode.h"
#include <iostream>


#define ll long long
#define hno hNode

using namespace std;
const int tableSize = 1301;

class HashMap{

    LinkedList<hno> hnl[tableSize];

public:

    int generateHashNum(ll hn, int tableSize){

        return (int)(hn % tableSize) % 1000;
    }

    void search(ll key){
        hno *temp;
        temp->setKey(key);
        ll index = generateHashNum(key,tableSize);
        hnl->search(hnl[index],temp);

    }

    void insert(hno hn){
        ll index = generateHashNum(hn.getKey(),tableSize);
        hnl[index].insertLast(hn);
    }





};