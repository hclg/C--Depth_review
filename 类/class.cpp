#include <bits/stdc++.h>
using namespace std;

class data {
//��Ԫ
friend data add(const data&, const data&);
friend ostream &print(ostream &, const data&);
friend istream &read(istream&, data&);
public:
    //�����Ĺ��캯��
    data() = default;
    data(const string &s) : bookno(s) {}
    data(const string &s, unsigned n, double p) : bookno(s), sold(n), reve(p*n) {}
    data(istream &);

    //֮ǰ��
    string isbn() const {
        avg();
        return this->bookno;
    }
    data & combine(const data&);
private:
    double avg() const {
        return sold ? reve/sold:0;
    }
    string bookno;
    unsigned sold = 0;
    double reve = 0.0;

};

class screen {
public:
    typedef string::size_type pos; //���ֶ���pos
    screen() = default; //��Ϊ����һ�����캯�������Ա�������Ҫ
    screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd,c) {}
    char get() const {///��ȡ��괦
    return contents[cursor];} //��ʽ����
    inline char get(pos ht, pos wd) const; //��ʾ����
    screen &move(pos r, pos c); //����֮����Ϊ����

    screen &display(ostream &os) {
    do_display(os); return *this;}
    const screen &display(ostream &os) const{
    do_display(os); return *this;}
private:
    void do_display(ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};
class window{
private:
    vector<screen> scr{screen(24,80,' ')};
};

inline
screen &screen::move(pos r, pos c) {
    pos row = r*width;
    cursor = row +c;
    return *this;
}
char screen::get(pos r, pos c) const { //�ڲ�����inline
    pos row = r*width;
    return contents[row+c];
}




data add(const data&,const data&);
ostream &print(ostream &, const data&);
istream &read(istream&, data&);

//data add(const data& a, const data& b) {
//    data sum = a;
//    sum.combine(b);
//    return sum;
//}

istream &read(istream &is,data &item) {
    double price = 0;
    is >> item.bookno >> item.sold >> price;
    item.reve = price * item.sold;
    return is;
}

ostream &print(ostream &os, const data &item) {
    os << item.isbn() << " " << item.sold << " "
        << item.reve << " " << item.avg();
    return os;
}

int main() {

    double a = 9;
    const double *const c = &a;
    const_cast<double *>(c);
    const double &d = a;
    const_cast<double *>(d);

//    decltype((int)) b = a;
//    cout << sizeof(decltype((int)) <<endl;
    return 0;
}
