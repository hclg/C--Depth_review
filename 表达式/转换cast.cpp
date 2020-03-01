#include <bits/stdc++.h>
using namespace std;


int main() {
    int a[10] = {0, 1, 2, 3, 4};
    void* S = &a;
    int *dp = static_cast<int*>(S);
    const char c0[] = "abcsdsd";
    const char *c1 = c0;
    string c2 = static_cast<string>(c1);
    char *c3 = const_cast<char*>(c1);
    c3[1] = '2';
    cout << c3 <<endl;
    cout << c0 << endl;
    decltype(a) k = {};
    int *ks = a;
    //    decltype(*ks) l;
    k[0] = 1;
//    ks[0] = 1;
    cout << sizeof S <<endl;
    string s, s1="sdsa";
    auto *p = &s;
    auto si = sizeof s, s2 = sizeof s1, s3 = sizeof(s1);
    auto pl = sizeof p, pll = sizeof *p;
    cout << si << " " << s2 << " " << s3 << endl;
    cout << pl << " " << pll << endl;
    return 0;
}

