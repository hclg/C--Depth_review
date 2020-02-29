#include <bits/stdc++.h>
using namespace std;
using int_array = int[4];
int main() {
    int as[3][4] = {{0}, {1}, {2}};
    cout << as[0][0] << as[0][1] << as[1][0] << as[1][1] << endl;
//    auto (row)[4]= {as[0],as[1],as[2],as[3]};
//    auto row = as;
    cout << row[1][1] << row[1][0] <<endl;
//    auto &row = as[1][0];
    size_t cnt = 0;

    for (auto &row : as)
        for (auto col : row) {
            cout << col << " ";
        }

    cout << row[0] << row[1] << endl;
    vector<int> ve{1,2,3};
    vector<int> v2{1,2,3};
    if (ve == v2)
        puts("sdsad");
    int a[] = {0,1,2,3,4};
    auto p = a+2;
    cout << p[-2] << endl;
    cout << end(a)-begin(a) <<endl;
    string k("11");
    auto i = k.size()-2;
    for (; i >= 0 && k[i] == '1';--i);
//    cout << i << endl;
    const unsigned sz = 3;
    int ial[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};
    string a4[3] = {"hi", "bye"};
//    int a5[2] = {0£¬1£¬2};
    char ch[5] = "csd";
    cout << a3[3] <<endl;
    return 0;
}
