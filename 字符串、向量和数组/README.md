# 字符串、向量和数组

### 1. 命名空间的using 声明

* 简单的声明方式：

  ```cpp
  using namespace::name; //如using std::cin;
  
  ```

* 可放多行

* 头文件中含有using后每个都会声明了

#### 1.1 string

> 位于#include<string>里的std中

* 定义和初始化string对象

  * `=`：拷贝初始化
  * 不用`=`：直接初始化

  ```cpp
  string s1; //空的
  string s2 = s1; //s1的副本
  string s3 = "yes"; //同上
  string s33("yes"); //同上
  string s4(10, 'c'); //s4 内容是十个c
  ```

* string 的操作

  ```cpp
  os<<s //将s写入输出流os当中，返回os
  is>>s //从is中读取字符串给s。字符串以空格分格，返回is
  getline(is, s) //从is中读取一行赋给s，返回is
  s.empty() //s为空返回true否则false
  s.size() //长度
  s[n] //返回s第n个字符的引用
  s1+s2 //返回s1和s2连接的结果
  s1=s2 
  s1==s2
  s1!=s2
  < <= > >= //利用字典序比较，对大小写敏感
  ```

* 读取未知对象

  ```cpp
  int main() {
      string s;
      while (cin >> s) //反复读取直到文件结束符
          cout << s << endl;
      return 0;
  }
  ```

##### 1.1.1 string::size_type 类型

* `size()`函数返回的是`string::size_type`类型值
  * 无符号值
  * 所以**注意**`(s.size() < n)`时如果n是负值 判断结果几乎是true；

##### 1.1.2 比较

* 按字典序大小比较
* 前面相同则短的小

* 运算是从左到右且两个之间必须有一个是string型

### 2. 处理string类型对象的字符

> 常用到的标准库在头文件`#include <cctype>`中

* 包含函数

  ```cpp
  isalnum(c) //当c是字母或数字为真
  isalpha(c) //当c是字母为真
  iscntrl(c) //当c是控制字符时为真
  isdigit(c) //当c时数字为真
  isgraph(c) //当c不是空格但可打印为真
  islower(c) //当c时小写字母时为真
  	upper
  isprint(c) //当c是可打印字符为真
  ispunct(c) //当c是标点符号为真
  isspace(c) //当c为空白是真
  stoll(c)   //转数字
  tolower(c) //转小写
      upper
  ```

  > c++11新语句for(range for) 遍历每个元素并对值进行操作

* **for**

  ```cpp
  for (declaration : expression)
      statement
  expression 部分是对象，表示一个序列
  declaration 部分负责定义一个变量，该变量用于访问序列的基础元素，每次迭代变成expression部分的下一个元素
  string str("some string");
  for (auto c : str) //c初始为str的元素
      cout << c << endl;
  for (auto &c : str) //c引用了str的元素，所以可以更改值
  	c+=1;
  cout << str << endl;
  
  ```

* 调用下标时不要越界

### 3. vector

> 常被称为容器 `#include <vector> std`中
>
> c++有类模板和函数模板
>
> vector是一个类模板， 模板本身可以看作一份说明，编译器根据模板创建类或者函数的过程称**实体化**

```cpp
vector<int> iv; //存放int
vector<vectot<string>> file; //向量元素是vector对象
```

* 引用不是对象，所以不包含在`vector`中

* 初始化

  ```cpp
  vector<T> v1; //空的
  vector<T> v2(v1); //含有v1所有元素的副本 
  vector<T> v2 = v1; //同上
  vector<T> v3(n, val); //包含m个重复元素，每个值都是val
  vector<T> v4(n); //包含n个重复性的初始化对象
  vector<T> v5{a,b,c...}; //初始化为各个值
  vector<T> v5={a,b,c...}; //初始化为各个值
  ```

  * 元素的类型必须对应

  * 初始化自定义元素列表只能是花括号

  * 当花括号元素类型不对应时，会自动考虑默认值初始化

    ```cpp
    vector<string> ve{10} //因为10int型考虑成，初始10个空元素
    vector<string> ve{10，"123"} //因为10int型考虑成，初始10个"123"元素
    ```

#### 3.1 向vector添加元素

* `push_back()`: 负责把元素压到尾端
* **注意**范围for语句不能改变遍历序列的大小

* `vector`：其他常用操作

  ```cpp
  v.empty() 判断空
  v.size() 取元素个数
  v.push_back() 压入元素
  v[n] 返回第n个元素的引用
  v1 = v2 拷贝
  v1 = {a, b, c...} 拷贝 
  v1 != v2
  v1 == v2
  <, <=， >, >= 以字典序进行比较
  ```

* 同样可以用`auto`

* `size`返回值为`size_type` 类型 必须

  ```cpp
  vector<int>::size_type; //正确
  vector::size_type; //错误
  ```

* 元素相同容量少的比容量多的小

* 大小关系与元素值定义的关系决定

#### 3.1 vector 内元素的索引

> 与string 下标索引一样

* 不能用下标形式添加元素
  * 会导致所谓的缓冲区溢出

### 4. 迭代器

> `iterator` 迭代器

* 所有标准库都可以使用迭代器
* 提供对对象的间接访问
* 有效迭代器
  * 指向某个元素
  * 容器中尾元素的下一个位置
  * 其余都时无效

#### 4.1 使用迭代器

> 和指针不一样的时，不是用取地址符
>
> 拥有迭代器的类型

* 成员
  * `begin` 和 `end` 成员 第一个元素或者最后一个元素的下一个位置

##### 4.1.1 运算符

* 标准容器迭代器的运算符

  ```cpp
  *iter 返回迭代器iter所指向的元素
  iter->mem 解引用iter并获取该元素的名为mem的成员，(*iter).mem相同
  ++iter 指向下一个元素
  --iter 指向上一个元素
   ==  != 判断是否相同指向相同元素，并不是指元素值
  ```

* 和指针类似

  * 可直接对值进行操作

##### 4.1.2 迭代器类型

* `iterator`能读写

  ```cpp
  vector<int>::iterator it;
  string::iterator it2;
  ```

* `const_iterator` 只能读

  > 和常量指针差不多

  ```cpp
  vector<int>::const_iterator it3;
  ```

##### 4.1.3 `begin和end` 运算符

* 如果对象是常量返回const_iterator;

* 如果不是返回iterator

  ```cpp
  vector<int> v;
  const vector<int> v2;
  auto it1 = v.begin(); 
  auto it2 = v2.begin(); const_iterator
  ```

  > c++11 为const_iterator 引入cbegin 和cend 
  >
  > 无论变量是什么都返回const_iterator

* 调用类对象的成员函数
  * 必须要加(*it).name(); 括号
  * 加括号和新号才是访问元素本身
  * 当然用 `->`也可以直接使用

##### 4.1.4 容易让迭代失效的操作

* 不能操作任何改变对象容量的操作 如`push_back`

#### 4.2 迭代器运算

> 在string和vector的迭代器中提供了额外更多的运算符，可跨越多个元素，支持运算关系

* 所支持的关系表

  | 操作        | 含义                                                  |
  | ----------- | ----------------------------------------------------- |
  | iter+n      | 迭代器加上一个整数依然是迭代器相当于移动n个位置返回值 |
  | iter-n      | 同上类似                                              |
  | iter+=n     | 加上赋值语句                                          |
  | iter-=n     | 同上                                                  |
  | iter1-iter2 | 得到距离的differece_type类型                          |
  | > >= < <=   |                                                       |

* `difference_type` 的带符号的整型数 距离 两个迭代器相减获得的结果类型

  * string 和 vector都定义了

* 用迭代器写的二分

  ```cpp
  auto beg = t.begin(), end = t.end(); //t的内容有序
  auto mid = t.begin()+(end-beg)/2;
  while (mid != end && *mid != ans) { //查找ans元素
  	if (ans < *mid)
          end = mid;
      else beg = mid;
      mid = beg+(end-begin)/2;
  }
  ```

  

### 5. 数组

> 类似标准库类型vector 的数据结构

* 不同点数组大小固定

* 定义和初始化

  ```cpp
  unsigned cn = 42;
  constexpr unsigned sz = 42;
  int arr[10]; //数组10个整数
  int *parr[sz]; //含有42个整数指针
  string dba[cnt]; //错误 不能用变量表达式
  string str[get_size()]; //当get_size() 是constexpr时正确
  ```

  * 数组定义时必须规定类型，不能用auto判断
  * 不存在引用数组

* 显示初始化数组元素

  > 列表初始化。如果忽略维度。
  > 编译器会根据初始值判断，相反如果声明知明维度，那初始值的总额不能超过维度大小。如果维度大于初始值则用靠前的元素，剩下的元素被初始化成默认值

```cpp
const unsigned sz = 3;
int ial[sz] = {0, 1, 2};
int a2[] = {0, 1, 2};
int a3[5] = {0, 1, 2};
string a4[3] = {"hi", "bye"};
int a5[2] = {0，1，2}; // 错误
```

* 字符数组额外提供一个初始化方式

  ```cpp
  char a[] = "c++"; //自动添加结束符的空字符
  char a4[3] = "c++"; //错误，没空间存放空字符
  ```

* 数组不能直接拷贝和赋值给另一个数组

* 稍微复杂的数组声明

  ```cpp
  int *pr[10]; //指针数组
  int &re[10] = /* --*/; //错误，引用错误
  int (*pra)[10] = &arr; //指向一个含有10个整数的数组
  int (&arre)[10] = arr; //引用一个含有10个整数的数组
  ```

  > 理解方法里到外 从右到左 ，先读括号内的，
  >
  > 所以第三个用例中，pra是指针-》它指向一个包含10个元素的int数组
  >
  > 引用相同

```cpp
int *(&arr)[10] = pr; //arr是个引用，它引用了一个指向包含10个整数的指针int型
```

#### 5.1 访问数组元素

> 数组也能使用下标索引，通常定义为`size_t`是一种无符号型的机器相关类型

> 在头文件`cstddef`里右定义size_t类型

```cpp
unsigned sc[11] = {}; //11个分段，全被初始化为0
```

```cpp
for (auto i : sc)  //对于sc
    cout << i << " "; //输出计数
cout << endl;
```

