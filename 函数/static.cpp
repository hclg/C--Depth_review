#include <bits/stdc++.h>
using namespace std;
int ss();
size_t count_c() {
    static size_t cnt;
    return cnt++;
}

int main() {

    for (int i = 0; i != 10; ++i)
        cout << count_c() << endl;
    return 0;

}
