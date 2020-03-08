# 类

> 类的基本思想时**数据抽象** 和**封装**。数据抽象依赖于**接口** 和**实现** 分离的编程技术

### 1. 定义抽象数据类型

#### 1.1 定义改进类

* 定义和声明成员函数的方式和普通函数的方式差不多

```cpp

class data {
public:
    string isbn() const {return bookno;} //成员函数返回值为string对象
    data & combine(const data&);
    double avg() const;
    string bookno;
    unsigned sold = 0;
    double reve = 0.0;
};

data add(const data&,const data&);
ostream &print(ostream &, const data&);
istream &read(istream&, data&);
```

* 引入this

  > 请求函数地址初始化this
  >
  > 调用isbn() 》类似  total.isbn()
  >
  > 编译器负责把total的地址传递给isbn的隐式函数形参this

  ```cpp
  //伪代码实际过程
  data::isbn(&total);
  ```

  * 任何对类成员的直接访问都被看作this的隐式引用

  ```cpp
  string isbn() const {return this->bookno;}
  this 是个常量指针总是指着这个对象
  ```

* 引入const成员函数

  * > isbn函数的另一个关键之处是紧随参数列表之后的const关键字，用于修改this指针类型

    * 默认情况下，this的类型是指向非常量版本的常量指针
    * 但把const放在后面，表示this是指向常量的指针 称为常量成员函数
    * 常量对象，常量的引用或指针只能调用常量成员函数

  * 编译器的分两部处理类

    * 首先编译成员声明，然后才到成员函数体，
    * 所以再成员函数体内使用其他成员的顺序无需在意

* 定义一个返回this对象的函数

  * > 设计雷士与复合运算的+=

  ```cpp
  data & data::combine(const data &r) {
      sold += r.sold;
      reve += r.reve;
      return *this;
  }
  ```

#### 1.2 定义类相关的非成员函数

> 用于辅助概念上是属于类的接口的组成部分
>
> 输入输出流

```cpp
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
```

* 定义add函数

  > 接收两个对象相加和

  ```cpp
  data add(const data& a,const data& b) {
      data sum = a;
      sum.combine(b);
      return sum;
  }
  ```

#### 1.3 构造函数

> 定义类对象的初始化方式

* 构造函数不能声明成const‘
  * 在const中写值完后，对象才能取得const称号
  * 会有默认初始化，默认构造函数

* 自定义构造函数
  * 如果存在类内初始值，用它初始化该成员
  * 构造默认初始化该成员
* 如果我们定义了构造函数，类将没有默认构造函数

```cpp

class data {
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
    double avg() const;
    string bookno;
    unsigned sold = 0;
    double reve = 0.0;
};
```

* = default 的含义

  * 表示我们也需要默认构造函数

  > c++11 要求编译器生成构造函数



### 2. 访问控制与封装

* `public`说明符定义类的接口

* `private`说明符之后的只能被成员函数访问

  ```cpp
  class data {
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
  ```

  * class或struct关键字唯一的区别就是说明符之前的成员类型
    * struct : public 默认
    * class : private 默认

#### 2.1 友元

> 既然数据成员已经变成private的，那我们的外部辅助函数就不能正常编译了

* 友元可以把函数作为他的友元可允许其他函数或类访问它的非公有成员

  ```cpp
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
  ```

  * 友元并非声明
  
* 如果一个类指定了友元类

  * 友元类的成员函数就可以访问此类包括非公有的所以成员

    ```cpp
    class screen {
        friend class window_mgr;
        //剩余部分在下面会讲
    }
    class window_mgr {
        //窗口编号
    	using screenindex = vector<screen>::size_type;
        //重置为空
        void clear(screenindex);
        private:
        vector<screen> screems{screen(24,80, ' ')};
    }
    void window_mgr::clear(screenindex i) {
        //s 是一个screen的引用, 指向我们想要清空的那个屏幕
        screen &s = screens[i];
        s.contents = string(s.height*s.width, ' ');
    }
    ```

    * 成员函数也可以做友元

      ```cpp
      class screen {
          ///window_mgr::clear必须在screen类之前被声明
          friend void window_mgr::clear(screenindex);
          //剩余部分
      }
      ```

      * 定义window_mgr 类。声明clear函数，不能定义它。在clear使用screen的成员之前必须先定义screen
      * 接下来定义screen，包括clear的友元声明
      * 最后定义clear，此时才能用screen成员

    * 调用友元函数时必须时要声明过的

      ```cpp
      struct x {
          friend void f(){/* 可以定义在函数内部*/} 
          x() {f();} //错f() 没声明
      }
      void x::x(){f();} 错误没声明
      void f();
      void x::x(){f();} //正确
      ```

      * 

### 3. 类的其他特性

#### 3.1 类成员再探

```cpp
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
```

* 定义在类内部的函数是自动inline的，因此构造和get函数默认inline，用inline声明的显示声明成员函数

```cpp

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
```

* 重载成员函数和非成员函数一样

* 可变数据成员

  * 关键字mutable

  * 永远不是const，即使是也能更改它本身的值

    ```cpp
    class screen{
        public:
        void spme_member() const;
        private:
        mutable size_t access_ctr;
    }
    void screen::spme_member() {
        access_ctr++; //保存调用次数
    }
    ```

    ```cpp
    class window{
    private:
        //默认情况下为空白的screen
        vector<screen> scr{screen(24,80,' ')};
    };
    ```

#### 3.2 返回*this 的成员函数

```cpp
class screen{
    public:
    screen &set(char);
    ///。。。。
        
    screen &display(ostream &os) {
    do_display(os); return *this;}
    const screen &display(ostream &os) const{
    do_display(os); return *this;}
private:
    void do_display(ostream &os) const {os << contents;}
}
inline screen &screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
//----------------
myscreen.move(4,0).set('#');//等价于下面两个

myscreen.move(4,0);
myscreen.set('#');

....
```

* const能重载

* > };
  > 和我们之前所学的一样，当一个成员调用另外一个成员时，this指针在其中隐式地传递。
  >      因此，当display调用do_display 时，它的this指针隐式地传递给do__ display。而当display的非常量版本调用do__ display 时，它的this指针将隐式地从指向非常量的指针转换成指向常量的指针当do_ display 完成后，display函数各自返回解引用this所得的对象。在非常量版本中，this 指向一个非常量对象，因此display返回一个普通的(非常量)引用;而const成员则返回一个常量引用。当我们在某个对象.上调用display时，该对象是否是const决定了应该调用
  > display的哪个版本:
  
* 每个类定义都是唯一的，即使成员一样，它们也不是同一个类型

* 类的声明

  * > 可以只声明类，不定义
    >
    > ```cpp
    > class screen; //声明
    > ```
    >
    > 一旦声明了，类就允许包括指向它自身类型的指针引用
    >
    > ```cpp
    > class link_screen {
    >     screen win;
    >     link_screen *next;
    > };
    > ```

  

### 4. 类的作用域

* 作用域运算符

  ```cpp
  screen::pos ht = 24, wd = 80;
  class window_mgr {
      public:
      //返回窗口编号
     	screenindex addscreen(const screen &);
      
  }
  window_mgr::screenindex
      window_mgr::addscreen(const screen &s) {
      screens.push_back(s);
      return screens.size()-1;
  }
  ```

  * 编译器处理完全部声明后才处理成员函数的定义
  * 先找函数体内，找不到在寻找外层声明
  * 内外层同时定义一样的类型名(using mx = int;)里外都定义了，会报错重定义mx；
  * 寻找过程都是从内到外一步一步来的
  * ：：变量名，这是直接显示访问全局变量

### 5. 构造函数再探

* 类成员中如果有const 型和引用，都必须初始话。而构造函数初始只能显示初始化

  ```cpp
  class A {
      public :
      A();
      private:
      int i;
      const int j;
      int &z;
  }
  A::A(int &x) : i(x), j(x), z(x) {}// 只用通过初始值列表提供初始值 
  ```

  * 尽量避免用成员初始化成员

* 委托构造函数

  > c++11 新标准扩展了构造函数初始值得功能

  ```cpp
  class A {
      public:
      A(string s, int c, double b) : no(s), so(c), re(b) {}
      //下面是委托构造函数
      A():A(" ", 0, 0) {}
      A(string s):A(s, 0, 0) {}
      A(istream &is):A() { 
      	read(is, *this);
      }   
  }
  ```

  * 先执行受委托的，在执行委托者的
  
* 使用默认构造函数

  ```cpp
      screen get(); //这是定义一个函数不是对象
      cout << get.get() << endl; //错误
  ```

* 类类型转换

  ```cpp
  data item;
      item.combine(string("sssss")); //隐式string转换成data，执行了接受string的构造函数
      item.combine(data("sssss")); //隐式转换string，显示转换data
  	item.combine(cin); //接受了一个istream类型的构造函数，隐式转换
  ```

  * 抑制构造函数的隐式转换，再构造函数前加上explicit即可
    * 此关键字值允许出现再类的构造函数声明处即可
    * static_cast 可以用explicit的构造函数

#### 5.1 聚合类

满足以下条件

* 所有成员都是public的
* 没有定义任何构造函数
* 没有类初始值
* 没有基类，也没有virtual 函数

```cpp
struct Data {
	int ival;
    string s;
}
```

> 可用花括号给成员初始值列表，初始化聚合类成员
>
> 顺序一致

#### 5.2 字面值常量类

* 数据成员都是字面值类型
* 类必须至少含一个constexpr 构造函数
* 如果一个数据成员含有类内初始值，则内置类型成员初始值必须是一条常量表达式；如果是某种类类型，必须使用自己成员的constexpr构造函数
* 类必须使用析构函数默认定义

```cpp

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
```

* constexpr 构造函数用于生成constexpr对象

  ```cpp
  constexpr Debug io_sub(false, true, false);
  if (io_sub.any())
      cerr << "...." << endl;
  ```

  

### 6. 类的静态成员

* 声明静态成员

  * 加上static

  * 该对象被所以该类对象共享
  * 不与任何一个对象绑定
  * 不包含this指针
  * 作为结果，不能声明成const
  * 不能再static 函数体内使用this指针

  ```cpp
  double r;
  r = Account::rate(); //使用作用域运算符
  ```

  * 