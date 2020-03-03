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

  