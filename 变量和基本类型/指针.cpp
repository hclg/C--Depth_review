#include <iostream>
using namespace std;
int sks = 4;
constexpr int sd = 4;
int main() {
    int i = 8, t = 4;
    int &r1 = i;
    const int *const ij = &i;
    const int *ks = &i;
    ks = &r1;
    int *const j = &i;
    const int &r2 = i;
    int &k = i, &s = k;
    r1 = 100;
    *j = 12;
    int *cp, *const p2 = cp;
    constexpr const int *pp = &sd;
    auto a = &i;
    a = 0;
    cout << r2 <<" " << sizeof(ij) << " " << sizeof(r2);
}
