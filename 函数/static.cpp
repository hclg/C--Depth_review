#include <bits/stdc++.h>
using namespace std;
int ss();
size_t count_c() {
    static size_t cnt;
    return cnt++;
}

typedef int in;
void pp(const in &i) {}
void pp(int &i) {}

const string &ff(const string &s) {
    return s;
}

string &ff(string &s) {
    auto &r = ff(const_cast<const string&>(s));
    const_cast<string&>(r) += "ss";
    return const_cast<string&>(r);
}

int fs(int a, int b, int c) {
    if(a == 1)
        return a+100000;
    else if (b == 1)
        return b+10;
    else return c;
}

constexpr int new_sz(int i) {
    return 33*i;
}
//
//class A {
//    int s;
//    void ff(int &a) const {
////        s++;
//    };
//};

int ks = 4;
int main() {
    int kss = 5;
    int a[new_sz(kss)];
    int fs(int, int, int = 3);
//    int fs(int, int, int = 3);
    int fs(int, int = ks, int);

    cout << fs(2,2);
    string &ff(string&);
    string s = "ss";
    ff(s) += "sdad";
    cout << s << endl;
    const string k = "sss55";
//    const string &f = ff(k);
    cout << k <<endl;
    for (int i = 0; i != 10; ++i)
        cout << count_c() << endl;
    return 0;

}
