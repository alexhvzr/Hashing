//
// Created by Alex on 11/15/2018.
//

#include "Item.h"
#include <time.h>
#define ll long long

class BarcodeArrayScanner{
Item* a = new Item[2000000];
int arrCount = 0;

public:
  void addArrItem(Item& item) {
        a[arrCount] = item;
        arrCount+=1;
    }


    void search(ll k){
        clock_t timer;
        timer = clock();
    for(int j = 0; j < 2000000; j++){
        if(k == a[j].getKey()){
            timer = clock() - timer;
            cout << "Array time: " << timer << " milliseconds." <<endl;
            break;
        }
    }
  }
//  ll* generateKeys(){
//      ll* temp = new ll[101];
//        for(int k = 0; k < 100; k++){
//            temp[k] = a[k*173%9].getKey();
//        }
//      return temp;
//  };
};