#include <bits/stdc++.h>
using namespace std;

class data {
//友元
friend data add(const data&, const data&);
friend ostream &print(ostream &, const data&);
friend istream &read(istream&, data&);
public:
    //新增的构造函数
    data() = default;
    data(const string &s) : bookno(s) {}
    data(const string &s, unsigned n, double p) : bookno(s), sold(n), reve(p*n) {}
    data(istream &);

    //之前的
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
    typedef string::size_type pos; //部分定义pos
    screen() = default; //因为有另一个构造函数，所以本函数需要
    screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd,c) {}
    char get() const {///读取光标处
    return contents[cursor];} //隐式内联
    inline char get(pos ht, pos wd) const; //显示内联
    screen &move(pos r, pos c); //能在之后被设为内联
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};
inline
screen &screen::move(pos r, pos c) {
    pos row = r*width;
    cursor = row +c;
    return *this;
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
    return 0;
}
