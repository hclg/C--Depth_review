#include <using.h>

int main()
{
    int k = -1;
    k<<=1;
    cout << k << endl;
    string s1 = "yes ";
//    string s2 = "sdas"+"dasdas"+s1; //s1�ĸ���
    string s3 = "yes"; //ͬ��
    string s4(10, 'c'); //s4 ������ʮ��c
    getline(cin, s4);
    vector<int>ve;
    for (int i = 0; i < 4; ++i)
        ve.push_back(i);
    for (char &c : s4)
        c+=1;
    for (char c : s4)
        cout << c << " ";
    puts("");
    if (s4.size() < -5)
        puts("sds");
    if (s1 > s3)
        cout << "YES" <<endl;
    return 0;
}
