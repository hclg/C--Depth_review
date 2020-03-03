#include <iostream>
#include <fact.cc>
using namespace std;

int ss(int x,const int y) {
    decltype(y) i = 5;
//    i = 6;
    return x+y;
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
    for (auto i : arr)
        cout << i << endl;
}

int main()
{
    vector<int>ve = {0, 1, 2, 3, 4, 5};
    int a[] = {0, 1, 2};
    print(a);
//    int *i = a;
//    for (;i;++i) cout << *i << endl;
//    cout << *ff(3, ve.begin()) << endl;
//    for (auto &i : ve) {
//        cout << i << endl;
//    }

    fs("sdad");
    int k;
    const int ks = k;
    cout << ss(1, 2) << endl;

    return 0;
}


