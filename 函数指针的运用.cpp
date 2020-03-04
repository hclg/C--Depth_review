#include <bits/stdc++.h>
using namespace std;
using F = int(*)(int, int);
typedef int (*F1)(int, int);

int add(int a, int b) {
    cout << __func__ << " :";
    return a+b;
}

int sub(int a, int b) {
    cout << __func__ << " :";
    return a-b;
}

int mult(int a, int b) {
    cout << __func__ << " :";
    return a*b;
}

int divi(int a, int b) {
    cout << __func__ << " :";
    return a/b;
}

typedef decltype(add) *F2;

int main() {
    int a, b;
    cin >> a >> b;
    vector<F> ve;
    ve.push_back(add);
    ve.push_back(sub);
    ve.push_back(mult);
    ve.push_back(divi);
    for (auto &i : ve)
        cout << i(a,b) << endl;
    return 0;
}
