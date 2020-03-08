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

data & data::combine(const data& t) {
        this->bookno += t.bookno;
        this->sold += t.sold;
        this->reve += t.reve;
        return *this;
    }

class screen {
public:
    typedef string::size_type pos; //部分定义pos
    screen() = default; //因为有另一个构造函数，所以本函数需要
    screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd,c) {}
    char get() const {///读取光标处
    return contents[cursor];} //隐式内联
    inline char get(pos ht, pos wd) const; //显示内联
    screen &move(pos r, pos c); //能在之后被设为内联

    screen &display(ostream &os) {
    do_display(os); return *this;}
    const screen &display(ostream &os) const{
    do_display(os); return *this;}
private:
    void do_display(ostream &os) const {os << contents;}
//    static int ss = 0;
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
char screen::get(pos r, pos c) const { //内部声明inline
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
data::data(istream &is) {
    is >> this->bookno >> this->sold >> this->reve;
}
struct A {
    int i;
    string s;
};

class Debug {
    public:
    constexpr Debug(bool b = true) : hw(b), io(b),other(b) {}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
    constexpr bool any() {return hw || io || other;}
    private:
        bool hw;
        bool io;
        bool other;
}

int main() {

    double a = 9;
//    screen get();
//    cout << get.get() << endl;
    int k = 5;
    int s(k);
    cout << s << endl;
    data item = {};
    data ss(item);
    item.combine(string("sssss"));
    item.combine(data("sssss"));
    item.combine(cin);
    cout << item.isbn() << endl;

    return 0;
}
