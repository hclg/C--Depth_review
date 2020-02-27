#include <iostream>
#include <Class.h>
using namespace std;
extern const int SS;
int main()
{
    Class a;
    a.put();
    a.a = 100;
    a.put();
    cout << SS << endl;
    return 0;
}
