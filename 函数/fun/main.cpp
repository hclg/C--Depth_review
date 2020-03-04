//#define NDEBUG
#include <iostream>
#include <bits/stdc++.h>
#include <fact.cc>
using namespace std;

int ss(int x,const int y) {
    decltype(y) i = 5;
//    i = 6;
    return x+y;
}
//int foo(int a, int b) {
//    return min(a, b);
//}
//int foo(int i,int b...) {
//    return min(i,foo(b...));
//}
auto func(int (*a)[3]) -> int(*)[3] {
    (*a)[1] = 3;
    return a;
}
string &sot(string &s1, string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}
void fs(const string &al) {
}
vector<int>::iterator ff(const int &k, vector<int>::iterator i) {
    for (int j = 0; j < k; ++j, ++i) {
        cout << *i << endl;
        cin >> *i;
    }
    return i;
}
void ffs(int a[10]) {}
void print(const int *beg, const int *end) {
    while (beg != end)
        cout << *beg++ << endl;
}

void print(int (&arr)[3]) {
    auto be = begin(arr);
    for (auto i : arr)
        cout << i << endl;
}

void print(int (*arr)[3], int rowsize) {

}

void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}
void error_msg(int e, initializer_list<string> il) {
    cout << e << ": ";
    for (auto &i : il) {
        cout << i << " ";
    }
    cout << endl;
}
//

vector<string> process() {
    return {"","sds"};
}

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0,2,4,6,8};
decltype(odd) *arr(int i) {
    return (i%2) ? &odd : &even;
}
//inline int &ss(int &a) {
//    return a;
//}
void print(const int ia[], size_t size) {
#ifndef NDEBUG
    //_ _func_ _是编译器定义的一个局部静态变量，用于存放函数名
    //是一个const char 的一个静态数组， 存放函数名
    cerr << __func__ <<" :array size is " << size << endl;

#endif // NDEBUG
}

void ffs(int a) {
}
void ffs(double a, double b=4.2) {
    cout <<"ffs";
}
void man(long a) {}
void man(double a){}
using F= int(*)(int*, int);
int main()
{
//    auto i -> int;
    cout << sizeof(F);
//    man(3);
//
//    ffs(3.2);
//    int lin = 5;
//    assert(lin == 0);
//    ss(lin) = 3;
//    cout << lin << endl;
    int a[] = {0, 1, 2};
    print(a, 3);

    func(&a);
    for (auto i : a) cout << i << endl;
//    return EXIT_FALLURE;
    vector<string>ss = process();
    cout << ss[1] << endl;
    string as = "ddad", bs = "sdada";
//    error_msg(4,{as, bs});
    string &k = sot(as, bs);
    k += "100";
    cout << as << endl;
    vector<int>ve = {0, 1, 2, 3, 4, 5};
//    int a[] = {0, 1, 2};
    int j[2] = {0, 1};
    print(begin(j), end(j));
    print(a);
//    int *i = a;
//    cout << *ff(3, ve.begin()) << endl;
//    for (auto &i : ve) {
//        cout << i << endl;
//    }

    fs("sdad");
//    int k;
//    const int ks = k;
//    cout << ss(1, 2) << endl;

    return 0;
}


