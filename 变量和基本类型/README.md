# 变量和基本类型（基于c++）

### <div id = “d1">1. 基本内置类型</div>

* `算术类型`: 字符、整数、布尔值、浮点数
* `空类型`：不对应具体的值，用于特殊场合

#### <div id = “d1_1">1.1 算术类型</div>

* 整型（布尔，字符）
* 浮点型

![算术类型](算术类型.png)

##### 1.1.1 存储

* 字节占8比特
* 字占32或64，也就是4~8字节

> 每个字节与一个数字（地址）关联
>
> 浮点型的第一个字节是ISO-Latin-1字符集，则就是分号，所以可以知道是浮点型

1. 浮点型
   1. float 32比特
   2. double 64比特
   3. long double 96~128比特
2. 字符型 
   1. char 8比特
      1. signed char 8比特
   2. unsigned char 8比特

#### 1.2 类型转换

> ​	unsigned char c = -1; // c =255
>
> ​	signed char c = 256; //c2 未定义

1. 含无符号的表达式

   * 例如：整数和无符号的运算会自动转化成无符号

     ```cpp
     unsigned u = 10;
         int i = -42;
         cout << i+i << endl;
         cout << u+i << endl;
         //-84
         //4294967264 32位
     ```

   * 无符号的负数时为取模后的值

#### 1.3 字面值

> 20 `十进制` 024 `八进制` 0x14 `十六进制`

* 字符串的组成是字符数组（字符串的末尾多一个‘\0’)

  ```cpp
  //分开字符串写法
  std::cout << "你好"
       "NO" << std::endl;
  // 你好NO
  ```

#### 1.4 转义序列

​	![image-20200226083536400](转义.png)

* 也可以用`\x 十六进制` `\八进制`

* 数值对应的字符集![sss](image-20200226084101078.png)

  ![image-20200226084332828](image-20200226084332828.png)

> ​	UL 会根据数值决定是unsigned long 还是unsigned long long

* 前缀为字符
* 后缀为整型或浮点型
* aen的后面数值表示a*10^n^

### 2. 变量

> 何为对象？
>
> ---
>
> `对象` :是指一块能存储数据并具有某种类型的内存空间。
>
> 对象也叫变量，而值是只读数据

#### 2.1 初始值

```cpp
///a 先被定义然后赋值， 随后用于初始化b
double a = 1.1, b = a*2;
```

* 列表初始化 int a{0};

#### 2.2 变量声明和定义

​	C++语言支持`分离式编译`机制，可分成若干个文件独立运行。

* 声明：变量声明规定了变量的类型和名字，不分空间
* 定义：申请存储空间，也可能给变量赋初始值

```cpp
extern int i; // 声明i并非定义i
int j; //声明j并定义j
```

> 变量只能被定义一次，但可以声明很多次

#### 2.3 表示符

![image-20200226103919393](image-20200226103919393.png)

#### 2. 4 名字的作用域

* 全局作用域
* 块作用域

##### 2.4.1 外层作用域

```cpp
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int reused = 42;//全局
int main(){
    int unique = 0; // 块
    cout << reused << " " << unique << endl;
    int reused = 0;
    cout << reused << endl; //局部覆盖了全局
    cout << ::reused << endl; //全局
    {
        int reused = 5;
        cout << reused <<endl; //局部覆盖局部
        cout << ::reused <<endl; //全局
    }
    return 0;
}
```

### 3. 复合类型

> 一条声明语句由一个人基本`基本数据类型` 和一个`声明符`列表组成

#### 3.1 引用

> c++11添加的 `右值引用`

* 定义：为对象起另外一个名字，引用类型引用另一种类型通过将声明符写成&d的形式。
* 引用必须初始化
* 引用并非对象

```cpp
    int i, &ri = i;
    i = 5; ri = 10;
    cout << i << " " << ri << endl; //10 10
	int &r = 0; //错误 不能是值
```

#### 3.2 指针

​	指针是“指向”另外一种类型的复合类型。实现了间接访问。

指针存放的是变量地址

```cpp
int i;
int *pi = &i;
int *p = pi;
```

*指针的四个状态*

* 指向一个对象
* 指向紧邻对象所占的空间的下一个位置
* 空指针
* 无效指针

> 在指针前面加*号得到指针p得对象。

![image-20200226125751785](image-20200226125751785.png)

空指针

```cpp
int *p1 = nullptr;//c++11得特殊字面值
int *p2 = 0;
int *p3 = NULL; //include <cstdlib>
```

> 注意不能给指针赋int变量。

##### 3.2.1 void* 指针

> void *是一种特殊的指针，可以存放任意对象的地址

```cpp
double obj = 3.14, *pd = &obj;
void *pv = &obj;
pv = pd;
```

* void* 指针只能比较
* 作为函数的输入输入输出
* 做另一个void*指针赋值
* 其他不能操作

##### 3.2.2 指向指针的指针

> 理解看法：

* 把变量名和前面的分开
  * 如 int **p;
  * 可以看出 int * 类型的指针* 变量名为p



#### 3.3 复合类型

* 声明

  例子：

  ```cpp
  int* p1, p2; //p1是指向int的指针，p2是int
  int ival = 11;
  int *pi = &ival; //指向ival的指针
  int **ppi = &pi; //指向指针的指针
  ```

  > 按我的理解声明可以从右向左看问题，它是什么就看变量前一个字符，如果是*它指针 其他前面的东西都是它的类型，如果是&那它就是引用，其他前面的都是类型

  例如：

  ```cpp
  int i = 42;
  int *p;
  int *&r = p; ///它是引用，是int指针型的
  r = &i;
  *r = 0;
  ```



### 4 const 限定符

> 有时我们希望, 定义一个值不会改变的变量

```cpp
const int buf = 512; //常量
const int i = get_size(); //正确
const int k; //错误
int f = 9;
const int c = f; //正确
```

* const 对象一旦创建就不能改变，所以一定要初始化

* const 对象只能再自身文件内使用，多文件的情况下不能共享// 但我的尝试发现可以共用的。。

  * 但是也有解决办法如下：

  * 不管是声明还是定义都添加extern关键字

    ```cpp
    //file.cc 定义并初始化一个常量，可以给其他文件访问
    extern const int buf = 5;
    //file.h 头文件
    extern const int buf; //与file.cc 中的buf一样
    ```

* const 引用

  ```cpp
  const int k = 5;
  const int *p = &k;
  int i = 42;
  const int &r1 = i; //常量引用是允许绑定普通int对象，但不能返过来
  const int &r2 = 5;
  int &r4 = r1*2; //错误
  double dval = 3.14; 
  const int &r5 = &dval; ///3 相当于const int tem = dval;const int &r5 = tem;
  //这就是临时量
  ```

  * const引用的作用

  ```cpp
  int i = 42;
  int &r1 = i;
  const int &r2 = i;
  r1 = 0; //正确
  r2 = 0; //错误 ，不能通过r2进行更改，但r2可以访问i；
  ```

  

##### 4.1 指针和const

> 指向常量的指针

```cpp
const double pi = 3.1;
double *ptr = &pi; //错误和引用一样类型不对，不能返过来。但常指针可以指向普通double
const double *cp = &pi; //正确
```



##### 4.1.1 const 指针

* 指针是对象引用不是

* 常量指针必须初始化

* 把*放在const 前说明指针是一个常量，不变的是指针本身的那个值而不是非指向的那个

  ```cpp
  int err = 0;
  int *const cur = &err; //cur一直指向err 但它能操作err的值
  const double pi = 3.1;
  const double *const pip = &pi; //指向常量的常指针
  
  ```

  

##### 4.1.2 顶层const

* `顶层`表示指针本身是个常量
* `底层`表示指针所指的对象是着常量

```cpp
int i = 0; //const的类型
int *const p1 = &i; //不能改变p1的值，顶层
const int ci = 42; //不能改变ci的值， 顶层
const int *p2 = &ci //允许改变p2的值，底层
const int *const p3 = p2; //靠右的是顶层，靠左的是底层
const int &r = ci; //用声明引用的都是底层
```

* 一般非常量可以换常量，反之不可

#### 4.2 constexpr 和常量表达式

> `常量表达式` 指值不会改变，且在编译过程中能得到计算结果的表达式

``` cpp
const int max_files = 20; // 是常量表达式
const int limit = max_files+1; // 是
int i = 27; //不是
const int sz = get_size(); //不是，直到运行才能获得的不是
```

> c++11的新规定， constexpr类型是验证是否是常量表达式的，声明constexpr肯定式个常量，且必须式常量表达式


```cpp
constexpr int mf = 20; // 是
constexpt int sz = size(); // 只有当size是个constexpr函数是才正确
```

##### 4.2.1 指针和constexpr

​	 **必须明确一点，constexpr只对指针有效，对所指的变量不影响**

```cpp
const int *p = nullptr; //p是一个指向整型常量的指针
constexpr int *q = nullptr; //q是一个指向整数的常量指针
//且它所指向的必须要在函数体外
```

 

### 5. 处理类型

#### 5.1 类型别名

> 是一个人名字，为了让复杂的名字变得简单明了

两种方法：

```cpp
typedef double wages; //同义词
typedef wages base, *p; //base 是double的同义词，p是double*的同义词
```

```c++11的新规则：```**别名声明定义类型的别名**

```cpp
using SI = Sales_item; //SI 与Sales_item同义词
```

##### 5.1.1 一些复杂复合例子

```cpp
typedef char *pstring;
const pstring cstr = 0; //cstr 是指向char类型的常量指针
const pstring *ps; //ps 是一个指针，它的对象是指向char的常量指针
```

* 以上可以看出不能完全安照原来的样子去用

#### 5.2 auto 类型说明符

> 编程时常常需要给表达式的值赋给变量，这就要求变量清楚知道表达式的类型
>
> 所以c++11引入auto类型说明符，能通过初始值推算变量类型。

* auto变量必须有初始值

```cpp
auto item = val1+val2; //item初始化为相加的结果
auto i = 0, *p = &i; //正确：i是整数、p是整数指针
auto sz = 0, pi = 3.14; //错误两个的类型不同
```

##### 5.2.1 复合、常量、auto

> 当编译器推断出来的auto类型有时候和初始值不完全一样，会事到改变结果类型，使其符合

```cpp
int i = 0, &r = i;
auto a = r; //a是一个整数(r是别名)

```

* auto 会忽略顶层const，同时底层const会保留。(个人理解就是相当于它的变量都不是常量，都可以修改)

```cpp
const int ci = i, &cr = ci;
auto b = ci; //是整数顶层被忽略了
auto c = cr; //是整数ci本身是顶层的
auto d = &i; //是一个整数指针
auto e = &ci; //是一个指向整数常量的指针
```

* 如果希望是顶层const ，指明就行

* 还可以引用

  ```cpp
  const auto f = ci;
  auto &g = ci; //是一个整数常量的引用
  ```

#### 5.3 decltype 类型指示符

> c++11 新标准引入的第二种类型说明符 **decltype**

* 作用是选择并返回操作数的数据类型
* 编译器饭分析表达式并得到他的类型，却不实际计算值

```cpp
decltype(f()) sum = x; //sum的类型就是函数f的返会类型
```

* decltype 处理顶层const 和引用的方式与auto有些不同

  ```cpp
  const int ci = 0, &cj = ci;
  decltype(ci) x = 0; //x的类型是const int
  decltype(cj) y = x; //y的类型是const int&， y绑定到变量x
  decltype(cj) z;   //错误引用必须初始化
  int i = 42, *p = &i, &r = i;
  decltype(r+0) b; //正确了加法的返回时是int型
  decltype(*p) c; //错误：c是int &，要初始化
  ```

  * 有些表达式返回引用类型（之后再细讲）
  * 这里的因为*指针的结果其实就是 int& 而并非int，它相当于别名

* 表达式里加上括号也可能会有所不同

* 变量是一种作为赋值语句左值的特殊表达式。加上括号就是引用类型了

  ```cpp
  decltype((i)) d; //错误引用，要初始化
  decltype((i+5)) e; //正确
  ```

  * 变量加两层括号就是引用

### 6. 定义数据结构

> c++允许自定义数据类型，而库类型，也是以类的形式定义的。

```cpp
struct Sales_data {
    std::string str;
    unsigned un = 0;
    double do = 0.0;
};
```

* 内部定义的名必须唯一与外部可重复跟局部变量类似

```cpp
struct Sales{...} a, *c;
Sales kk, *ks;
```

> 跟c语言种的结构体类似。
>
> c++11新规定。可以为数据成员提供一个类内初始值。

#### 6.1 编写自己的头文件

> 为了确保各个文件中类的定义一致，类通常定义再头文件中，头文件和类名一样。

* 头文件也能用其他头文件的功能。
* 使用用过其他头文件的头文件，也需要再一次包含它所用过的头文件

**预处理器**:

​	`#include `： 指定头文件

​	`#define`:预处理变量

​	头文件保护符用于检测预处理变量：

```cpp
#ifdef //当且仅当变量已定义时为真，
#ifndef //当且仅当变量未定义时为真
当检测为真时，则后续操作到 #endif为止
```

```cpp
#ifndef STATUS_H
#define STATUS_H
#include <string>
struct sda{
    std::string bo;
    unsigned un = 0;
    double re = 0.0;
};
#endif
```

* 如果为真继续执行
* 如果为假ifndef到endif之间的部分将略过

> 注意用多文件的时候有些软件需要导入路径