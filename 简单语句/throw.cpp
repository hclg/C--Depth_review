#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    runtime_error er("error a+b<10");
    while (cin >> a >> b) {
        try {
            int i;
            if (a+b > 10)
                throw runtime_error("a+b>10");
            else if (a+b < 10)
                throw er;
            cout << a/b << endl;

        }catch (runtime_error err){

            cout << err.what()
                << "\n Try Again? Enter y or n" <<endl;
            char c;
            cin >> c;
            if (! cin || c == 'n')
                break; // Ìø³öwhile
        }
    }
    return 0;
}
