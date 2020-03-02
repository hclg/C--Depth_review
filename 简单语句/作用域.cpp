#include <bits/stdc++.h>
using namespace std;

int main(void) {
//    int *p;
//    {
//        int k = 5;
//        p = &k;
//    }
//    cout << k; //错误在作用域外没有声明它
//    cout << *p; //正确指向了作用域内的它，内存没有消亡一样可以用
//    cin >> *p;
    char ch = '3';
//    double s = 1.2;
    int ix = 10;
    goto begin;
        ix = 4;
        cout << ix << endl;
    end:
//        ix  = 42;
        ix = 3;
    begin:
        int sz = 5;
        cout <<  sz <<endl;
    cout << ix << endl;
    switch(ch) {
    case '1': {
        int i = 5;
    }
        int j;
//        ks = 5;
    break;
    case '3':
        j = 6;
        cout << j;
        int ks;
    default:
        {
        }

    }
    while (int s = 5) {
        s = 6;
    }
    long long ks = 5;
    long long *p[3];
    p[0] = &ks;
    int t = 1;
    while (t <= 2) {
        long long k = t*2;
        p[t++] = &k;
    }
    cout << *p[0] << endl;
    cout << *p[1] <<endl;
    cout << *p[2] <<endl;
//    cout <<i;
    return 0;
}
