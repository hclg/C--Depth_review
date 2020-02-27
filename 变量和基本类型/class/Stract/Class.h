#include <iostream>
using namespace std;
#ifndef CC
#define CC cout << a << endl
const int SS = 100;
struct Class {
    int a = 0;
    void put() {
        CC;
    }
};

#endif // CC
