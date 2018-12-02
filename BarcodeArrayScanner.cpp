//
// Created by Alex on 11/15/2018.
//

#include "Item.h"
#include <time.h>


class BarcodeArrayScanner {
    Item *a = new Item[2000000];
    int arrCount = 0;

public:
    void addArrItem(Item &item) {
        a[arrCount] = item;
        arrCount += 1;
    }

    void search(string k) {
        clock_t timer;
        timer = clock();
        for (int j = 0; j < 2000000; j++) {
            if (k == a[j].getKey()) {
                timer = clock() - timer;
                int ms = double(timer) / CLOCKS_PER_SEC * 1000;
                cout << "Array search time: " << ms << " milliseconds." << endl;
                break;
            }
        }
    }

};