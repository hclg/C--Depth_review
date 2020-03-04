# 函数

### 1. 函数基础

> 内容包括：返回值，函数名，0至多个参数的列表和函数体

* 调用函数的两项工作：

  1. 实参初始化为对应的形参
  2. 将控制权转移给被调用函数

  > 调用return时返回值用于初始化调用表达式的结果，控制权回到main

  #### 1.1 实参和形参

  * 实参是形参的初始值
  * 求值顺序没规定
  * 形参可以为空

  ```cpp
  void f1() {} //隐式
  void f2(void) {} //显示
  ```

#### 1.2 函数返回类型

> 返回类型不能是数组类型或者函数类型，但可以是指向数组或函数的指针。

* 形参和函数体定义的变量都称为是局部变量

* 块执行期间的对象叫自动对象
* 函数开始时为形参申请空间，函数终止形参消亡

#### 1.3 局部静态变量

> 在程序的执行路径上第一次经过对象定义语句时初始化，并且直到程序终止才消亡，因此函数结束也不会对它有影响

```cpp
#include <bits/stdc++.h>
using namespace std;

size_t count_c() {
    static size_t cnt = 0;
    return ++cnt;
}

int main() {
    for (int i = 0; i != 10; ++i)
        cout << count_c() << endl;
    return 0;
}
 ///会输出1到10
```

* 如果没有显示初始值，他将执行值初始化内置类型为0

#### 1.4 函数声明

> 可只有声明没有定义

* 声明可以省略形参

```cpp
void print(int a, int b);
```

* 建议把函数放在头文件里声明源文件定义

* 一个项目只能有一个main函数，这个函数就是开始执行的函数

#### 1.5 函数传参

> 所有的传参都跟新定义变量赋值一样

```cpp
如同：新定义了形参
    int a, b; //假设这是实参
	int c = a, *d = b, &e = b; 这是形参
        所以c改变不了a，但d,e可以
```

* 不支持拷贝的类型可以通过引用来访问对象

  * 因为某些对象占用的内存可能会很大，所以对于那些实参我们尽量用引用

  > 当无需修改值时用引用比较省内存

  >  可以利用引用参数当多余需要的返回值，因为函数只能返回一个值

### 2 const 形参和实参

> 当形参时const时，会忽略掉顶层const

* 形参有const时，传实参，是不是常量都行
* 但传过来的也是只能读不能写
* 虽然允许多定义相同名字的函数，但参数需不同，const的参数类型是和没加const相同的。
* 但利用decltype取到的还是const类型

```cpp
void fun(const int i ){}
void fun(int i) {} //错误上面定义过了
```

我们可以使用非常量初始化一个底层const，但反过来就不行

```cpp
vector<int>::iterator ff(const int &k, vector<int>::iterator i) {
    for (int j = 0; j < k; ++j, ++i) {
        cout << *i << endl;
        cin >> *i;
    }
    return i;
} //这个也能更改容器里的元素
```

#### 2.1 数组形参

> 特性：不能拷贝数组，数组通常会将其换成指针所以传数组就是传头指针

```cpp
void print(const int*);
void print(const int[]);
void print(const int[10]);//上面三个等价，这里的维度是我们期望数组含有多少，实际不一样
int i = 0, j[2] = {0, 1};
print(&i); 
print(j); //都可以因为j转换成&j[0];
```

* 使用时必须保证不能越界

* 字符数组本身可以做结束标记符

  * 对于int等这样的就不行了

  ```cpp
  char cp[] = "sdad";
  if (*cp) //若cp不是空字符
  ```

* 管理数组的好方法就是传首尾字符的指针

  ```cpp
  void print(const int *beg, const int *end) {
      while (beg != end)
          cout << *beg++ << endl;
  }
  int j[2] = {0, 1};
  print(begin(j), end(j));
  ///或者可以选择传人数组维度
  ```

* 允许变量定义成数组引用，形参也行

  * 但要规定好维度属于类型的一部分

  ```cpp
  void print(int (&arr)[3]) {
      for (auto i : arr)
          cout << i << endl;
  }//是可以的
  ```

  #### 2.2 多维数组

  > 首元素的本身就是数组，指针就是一个指向数组的指针。所以第二维的维度大小也是数组类型的一部分，不能省略

  ```cpp
  void print(int (*arr)[3], int rowsize) { //指向由3个数组元素构成的数组指针
  }
  void print(int arr[][3], int rowsize) {} //等价
  ```

  #### 2.3 main

  主函数是可以传参的，

  ```bash
  prog -d -o ofile data0
  ```

  ```cpp
  int main(int argc, char *argv[])//
      argc: 字符串的数量
       argv: 字符串数组
  ```

  按照执行输入的顺序输入你的argv

#### 2.4 含可变形参的函数

> 当不确定传入实参的数量时，c++11新标准提供了两种主要方法：如果所有的实参类型相同，可以传递一个名为initializer_list 的标准类型；
>
> 如果实参的类型不同，我梦编写一种特殊函数可变参数模板

* c++还有一种特殊形参类型``省略符``,可以用它表示可变数量的实参

  >  一般用于与c函数交互的接口程序

##### 2.4.1 initializer_list 形参

> 标准库类型用于表示某种特定类型的值的数组定义在同名的头文件里

![image-20200303110043895](image-20200303110043895.png)

* 和vector一样时模板类型

* 要定义所含元素类型

  ```cpp
  void error_msg(initializer_list<string> il) {
      for (auto beg = il.begin(); beg != il.end(); ++beg)
          cout << *beg << " ";
      cout << endl;
  }
      error_msg({"nihao", "sda"});
  ```

* 元素永远是常量无法更改

* 传递值得序列，必须放入花括号中

  ```cpp
  void error_msg(int e, initializer_list<string> il) {
      cout << e << ": ";
      for (auto &i : il) {
          cout << i << " ";
      }
      cout << endl;
  }
      string as = "sddad", bs = "sdada";
      error_msg(4,{as, bs});
  ```

##### 2.4.2 省略符形参

> 为了c++访问某特殊得c代码设置得，这些代码用了varargs的c标准库

* 大多数类类型对象无法通过省略符传递形参正确拷贝

* 只能出现在形参列表的最后一个位置

* 省略号对应的类型无需检测

  ```cpp
  void foo(parm_list, ...);//指定部分形参类型,后面的逗号是可选
  void foo(...); //
  ```

### 3. 返回类型和return语句

#### 3.1 return

1. 无返回值void型时有隐式return，可不用加return结束

2. 有返回值，返回的类型必须与函数返回的类型一致或隐式转换成返回类型

   ###### 值是如何被返回的

   > 和初始化一个变量或形参的方式完全相同：返回值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。

   ```cpp
   const string &shortstring(const string &s1, const string &s2) {
       return s1.size() < s2.size() ? s1 : s2;
   } //形参和返回类型都是const string 的引用，不管是调用函数还是返回值都不会真正的拷贝对象。
   
   ```

   * 不要指向和引用局部变量
     * 函数结束后会消亡

```cpp
int *pp() {
    int k = 5;
    return &k; //错误引用局部变量
}
```

*  引用返回左值

> 调用一个引用的函数得到左值，其他右值

```cpp
string &sot(string &s1, string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}
string as = "ddad", bs = "sdada";
string &k = sot(as, bs);
k += "100";
cout << as << endl;// 这个能更改as
/--------------------------------------------------------------
char &get_va(string &str, string::size_type ix) {
    return str[ix]; //假定索引有效
}
int main() {
    string s("a val");
    cout << s << endl;
    get_va(s, 0) = 'A';
    cout << s << endl; /// 输出A val
    return 0;
}
```

* 列表初始化返回值

* > c++11 新标准， 函数可以返回花括号包围的值的列表。可以为类似其他返回结果

  * 用来对函数返回的临时量进行初始化

    ```cpp
    vector<string> process() {
        return {"","sds"};
    }
    ```

    * main函数的返回值可机器隐式写入
      * 返回值0表示成功，非0含义根据机器而定，我返回其他的并没报错
      * 但程序会告诉你你返回的是啥



#### 3.2 递归

> 函数调用了自身，函数调用自身是会用到程序栈空间的

#### 3.3 返回数组指针

> 数组不能拷贝，所以函数返回数组只能通过数组指针或者引用

```cpp
typedef int arrT[10]; //arrT 是一个类型别名，他表示的类型是含有10个
using arrT = int[10]; //arrT等价声明
arrT* func(int i); //func 返回一个指向10个整数的数组指针
```

也可以直接声明：

```cpp
int arr[10];
int *p1[10];
int (*p2)[10] = &arr; // p2是个指针，它指向含有19个整数的数组
```

* 维度必须确定

  所以函数的为：

  ```cpp
  int (*func(int i))[10];
  func(int i) 表示需要一个int类型的实参
  (*func(int i)) 意味着我们可以对函数调用的结果执行解引用
  int (*func(int i))[10] 表示解引用得到的是一个大小为10的数组，数组的元素是int型的
  ```

#### 3.4 使用尾置返回类型

> c++11新标准中还有一种可以简化上述func声明的方法就是尾置返回类型
>
> 任何函数定义都可以用，对于复杂的最有效

* 在形参列表后面并以一个->符号开头。为了表示函数真正的返回类型，类型的位置放auto

  写法如下：

  ```cpp
  auto func(int i) -> int(*)[10]; 表示和上面的等价
  auto func(int (*a)[3]) -> int(*)[3] {
      (*a)[1] = 3;
      return a;
  }
      int a[] = {0, 1, 2};
      func(&a);
  ```

* 使用decltype

  通过函数返回的指针指向哪个数组，就可以用此关键字的返回类型

  ```cpp
  int odd[] = {1, 3, 5, 7, 9};
  int even[] = {0,2,4,6,8};
  decltype(odd) *arr(int i) {
      return (i%2) ? &odd : &even;
  }
  ```

  

### 4 函数重载

> main函数不能重载

* 名字相同但形参列表不同的我们称为函数重载

* 虽然调用定义相同的函数名，但编译器会根据实参的类型确定调用的函数

  * 所以对于重载函数，他们应该是在形参数量或形参类型上有所不同。
  * 不允许所有要素相同
  * 对于多个函数可匹配时，会发生二义性错误
  
  ```cpp
  void print(const char *cp);
  void print(const char *beg, const int *end);
  ...
  ```
```
  
  * 编译器会根据传入实参类型去选择
  
  定义重载函数
  typedef int in;
  void pp(int i);
  void pp(in i); //错误 ：这两个是相同的所以不行
  double pp(in i); //错误，形参一样
  string pp(const int i); //错误普通形参类型不区分const
  string pp(const int *i);
  string pp(int *i); //可以 引用和指针可以区分const //非常量的对象或指针，会优先选用非常量版本的函数
  void pp(double i); //这个可以类型不同
```

```cpp
# const_cast的用法
const string &ff(const string &s) {
    return s;
}
string &ff(string &s) {///利用它进行转换，实现与上面相同的功能且返回普通的string&是安全的
    auto &r = ff(const_cast<const string&>(s));
    return const_cast<string&>(r);
}
```

#### 4.1 重载作用域的区别

* 作用域里出现的同名类型会隐藏掉外界的重载函数

  * 外层同名的类型都会被隐藏

  ```cpp
  string read();
  void print(const string &);
  void print(double);
  void foof(int ival) {
      bool read = false;//新作用域，隐藏了外层的read
      read();//错误 read被隐藏了，不是函数
      void print(int); //新作用域，隐藏外层的print
      print("vv");//错误
      print(ival); //正确 print(int);可见
      print(3.1); //正确转为int调用print(int);
  }
  ```

  

### 5 . 特殊用途特性

#### 5.1 默认实参

>  某系函数的形参可含有默认实参，在调用的时候可以省略该实参

```cpp
string sc(int h, int k = 55, char s= ' ');
```

* 一个形参用了默认值后面的必须要用

  ```cpp
  //调用
  string k;
  k = sc();//错误h形参没有默认值
  k = sc(3);//正确等价于 sc(3, 55, ' ');
  k = sc(3, 33);//正确等价于 sc(3, 33, ' ');
  k = sc(3, 22, '#');//正确等价于 sc(3, 22, "#");
  k = sc(3, , 's'); //错误只能省略尾部实参
  ```

  * 添加默认形参 同个形参只能被添加一次

    ```cpp
    int fs(int, int, int = 3);
    int fs(int, int, int = 3);// 错误重复定义
    int fs(int, int = 1, int); //正确添加为 fs(int, int = 1, int = 3);
    ```

    * 局部变量不能默认实参

    ```cpp
    int ks = 4;
    int a = 5;
    int fs(int = a, int = ks); //ks 和a必须在函数体外 
    void f2() {
        ks = 3;
        int kk = fs(); //调用了fs(5, 3);
    }
    ```

#### 5.2 内联函数和constexpr 函数

> 调用函数其实包含一系列工作：调用前要保存寄存器，并返回时恢复；可能需要拷贝实参；转向另一个位置继续执行

* 内联函数可避免函数开销

  ```cpp
  inline const string & shorterString(const string &s1, const string &s2) {
      return s1.size() <= s2.size() ? s1:s2;
  }
  cout << shorterString(s1, s2) << endl;
  cout << (s1.size() <= s2.size())? s1 : s2 << endl;等价
  ```

  * 消除函数运行时的开销
    * 一般用于规模较小、流程直接、频繁调用的函数。如一个75行的函数不大可能在调用点被内联展开

* constexpr 函数

  * 函数返回类型和形参类型都是字面类型

  * 且必须包含return语句

    ```cpp
    constexpr int new_sz() {return 33;}
    constexpr int foo = new_sz(); //正确foo是常量表达式
    ```

    * 编译器能验证new_sz 的返回值是常量表达式

    * 为了能在编译过程中随时打开， constexpr函数会隐式指定为内联函数

    * 函数体内不能另外声明，但可以，有空语句，类型别名，using声明等

      ```cpp
      constexpr size_t scl(size_t cnt) {return new_sz()*cnt;}
      int arr[scl(2)]; //正确：scl(2)是常量表达式
      int i = 2;
      int a2[scl[i]]; //错误scl(i) 不是常量；虽然我的编译器没有报错
      ```

      * 当我们用非常量调用时，返回值也是一个非常量
      * 书上说可以多次定义，但我的编译器并没实现报错了
      * 但很同意把它放入头文件里

#### 5.3 调试帮助

> 头文件保护的技术，以便选择地执行调试代码，当应用编写完成准备发布时要先屏蔽调试代码。

* 这种方法用到两项预处理功能： assert 和NDEBUG 

  * `assert`:是一种预处理宏，其实就是一个预处理变量类似内联函数。用表达式作为它的条件

    > assert(expr);

  * 先对expr求值，如果表达式为假，assert 输出信息并终止程序的执行。 如果非0为真，assert什么都不做

  * 在头文件cassert中

```cpp
    int lin = 5;
    assert(lin == 0);//会终止程序
//Assertion failed: lin == 0, file D:\工作缓存区\git\C--Depth_review\函数\fun\main.cpp, line 79
```

* NDEBUG 预处理变量

  > assert 的行为依赖域一名为NDEBUG的预处理变量的状态。如果定义了NDEBUG，则assert什么都不做，默认没有定义时，assert会执行运行时检测

  我们可以语句定义NDEBUG ，关闭调试状态。

  ```bash
  CC -D NDEBUG main.c
  等价与main.c里写#define NDEBUG >>要放在最开始
  或者如果NDEBUG未定义
  void print(const int ia[], size_t size) {
  #ifndef NDEBUG
      //_ _func_ _是编译器定义的一个局部静态变量，用于存放函数名
      //是一个const char 的一个静态数组， 存放函数名
      cerr << __func__ <<" :array size is " << size << endl;
  
  #endif // NDEBUG
  }
  ```

  * 还有4个程序调试有用的

  | 名字             | 含义                     |
  | ---------------- | ------------------------ |
  | `__FILE__`       | 存放文件名的字符串       |
  | `__LINE__`       | 存放当前行号的整型字面值 |
  | `__TIME__`       | 存放文件编译时间的字符串 |
  | `__DATE__`       | 存放文件编译日期的字符串 |
  | 用于描述错误信息 |                          |

### 6. 函数匹配

在大多数情况下，我们容易确定某次调用应该选用哪个重载函数

* 确定候选函数和可行函数

  * 候选函数集

    > 函数名同名，声明调用点可见

  * 可行函数

    > 形参数量与实参数量一致，实参类型与形参类型相同，或者能转换形参类型

    ```cpp
    double ss(int);
    double ss(double, double = 5.2);
    ss(5.3); //会调用第二个，因为有默认实参，且用double不会损失精度，如果没有第二个，就会调用第一个
    
    void ffs(int a, int b) {
    }
    void ffs(double a, double b) {
    }
    ffs(3,3.2); //错误二义性，系统无法确定哪个脱颖而出
    ```

    

#### 6.1 实参类型转换

> 为确定最佳匹配，转换划分等级，排序如下：

1. 精确匹配

   1. 类型相同
   2. 实参从数组类型或函数类型转换成对应的指针类型
   3. 向实参添加顶层const 或删除顶层const

2. 通过const转换实现匹配

   如果是引用或指针是否用const ，则通过实参是否常量来选择

3. 通过类型提升实现匹配

4. 通过算术类型转换

   1. 如：一个接收int，一个接收short，则只有当提供short才选择short，即便是很小的整数

   2. 从int转unsigned int 并不比int 转double 高，

      ```cpp
      void man(long);
      void man(float);
      man(3.1); //二义性
      ```

5. 通过类类型转换

### 7. 函数指针

> 函数指针指向的是函数而非对象，函数类型由他的返回类型和形参类型共同决定

```cpp
bool lens(const string &, const string &);
bool (*p)(const string &, const string &);// 为初始化与函数指针
```

* 使用函数指针

  > 当我们把函数名做一个值来用时，该函数会自动转换成指针，
  >
  > ```cpp
  > p = lens; //pf指向lens函数
  > p = &lens; //等价，取地址符可选的
  > //使用指针调用函数时，可以无需解引用
  > bool b1 = p("ss", "ssa"); //调用lens函数
  > bool b2 = (*p)("ss", "ssa"); //等价
  > bool b2 = lens("ss", "ssa"); //等价
  > ```

  * 指针指向的类型必须相同，可以用nullptr和0赋值表示没有指向

* 重载函数指针

  * 通过指针类型选定

  > 当我们使用重载函数时，必须清晰定好选用的函数

  ```cpp
  void ff(int *);
  void ff(unsigned int );
  void (*pf)(unsigned int) = ff; //pf 指向第二个
  ```

* 函数形参

  ​	和数组类似，虽然不能定义函数类型的形参，但时可以为指向函数的指针

  ```cpp
  void uses(const string &s1, const string &s2, bool pf(const string &, const string &));
  //第三个类型是函数类型，他会自动转换成函数指针
  void uses(const string &s1, const string &s2, bool (*pf)(const string &, const string &)); // 等价
  uses(s1, s2, lens); //可以直接把函数当实参使用，会自动转换
  ```

  * 可利用decltype简化

    * 不会因函数自动转指针

    ```cpp
    typedef bool Func(cosnt string &, const string &);
    typedef decltype(lens) Func2; 
    //函数等价类型
    typedef bool (*Fun2)(cosnt string &, const string &);
    typedef decltype(lens) *Fun1;  //指针等价类型
    ```

  * 返回指向函数的指针

    > 和数组相似

    ```cpp
    using F = int(int *, int ); //F是一个函数类型
    using PF = int(*) (int *, int ); //PF是指针类型
    ```

    * 返回类型并不能自动转成地址，所以要显示的返回指针类型

      ```cpp
      PF f1(int); //正确
      F f1(int); //错误。 F是函数类型
      F *f1(int); // 正确
      int (*f1(int))(int *, int); //正确
      auto f1(int) -> int (*)(int*, int);//正确
      ```

      * 如果我们明确知道返回的函数时，就能用decltype。同样要在声明的时候加上显示的*号。
      * 存入函数指针的vector

```cpp
#include <bits/stdc++.h>
using namespace std;
using F = int(*)(int, int);
typedef int (*F1)(int, int);

int add(int a, int b) {
    cout << __func__ << " :";
    return a+b;
}

int sub(int a, int b) {
    cout << __func__ << " :";
    return a-b;
}

int mult(int a, int b) {
    cout << __func__ << " :";
    return a*b;
}

int divi(int a, int b) {
    cout << __func__ << " :";
    return a/b;
}

typedef decltype(add) *F2;

int main() {
    int a, b;
    cin >> a >> b;
    vector<F> ve;
    ve.push_back(add);
    ve.push_back(sub);
    ve.push_back(mult);
    ve.push_back(divi);
    for (auto &i : ve)
        cout << i(a,b) << endl;
    return 0;
}
```

