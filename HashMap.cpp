//
// Created by Alex Hayden van Zuiden-Rylander on 11/29/18.
//

#include "HashNode.h"

#define hno hNode


using namespace std;
const int tableSize = 1000;

class HashMap {

    LinkedList<hno> hnl[tableSize];

public:

    int generateHashNum(string hn, int tableSize) {
        int sval = 0;
        for (int i = 0; i < hn.length(); i++) {
            sval = sval + hn[i];
        }
        return sval % 1000;
    }

    void search(string key) {
        hno temp(key, "");
        int index = generateHashNum(key, tableSize);
        clock_t timer;
        timer = clock();
        bool found = hnl->search(hnl[index], temp);
        timer = clock() - timer;
        int ms = double(timer) / CLOCKS_PER_SEC * 1000;
        if (found) {
            cout << "Hash table search time: " << ms << " milliseconds." << endl;
        }

    }

    void insert(hno hn) {
        int index = generateHashNum(hn.getKey(), tableSize);
        hnl[index].insertLast(hn);
    }


};