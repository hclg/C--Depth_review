#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    auto it1 = v.begin(), it2 = it1;
    it1 += 2;
    it2 += 4;
    auto it = v.begin()+v.size()/2;
    cout << it2-it1 << endl;
}
