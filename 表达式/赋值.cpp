#include <iostream>
#include <vector>
using namespace std;


int main() {
    int i;
    double d;
    i = {1};
    d = {3};
    d = i = 3.5;
    vector<int> ve = {0, 1, 2};
    auto be = ve.begin();
    auto &io = cin;
//    io >> i;
    unsigned char bit = 1;
    cout << (1uLL<<33) << endl;
    cout << *++be <<endl;
    cout << *be++ <<endl;

    cout << i << " " << d << endl;
    return 0;
}
