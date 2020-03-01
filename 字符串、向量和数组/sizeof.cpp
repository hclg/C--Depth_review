#include <bits/stdc++.h>
using namespace std;


int main() {
    int a[10] = {0, 1, 2, 3, 4};
    void* S = &a;
    int *dp = static_cast<int*>(S);
    char
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
