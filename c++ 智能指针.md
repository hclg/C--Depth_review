# c++ 智能指针

* 动态内存用堆来存储

* 头文件`memory`

* 普通指针容易出现问题

  * 忘记释放内存
  * 产生非法指针

* 智能指针

  * 负责自动释放指向对象

* 类别：

  * shared_ptr 允许多个指针指向一个对象
  * unique_ptr 独占所指向的对象
  * weak_ptr 伴随类一种弱引用指向shared_ptr管理的对象

* 不同的用法及创建方式

  ```cpp
  shared_ptr<string> p1;
  shared_ptr<list<int>>p2;
  ```

  * 本身可用来判断是不是为空
  * p1.get() 返回p1所保存的指针
  * p.swap(q) 交换指针
  * 普通指针用的它都能

* shared_ptr独有的

  ```cpp
  make_shared<T>(args) 返回一个shared_ptr,指向动态分布的T类型对象，使用args初始化对象
  shared_ptr<T>p(q); 拷贝，递增q的计数器。
  p = q 拷贝，递减p的引用计数,递增q的引用计数；若p引用计数变成0，原内存释放
  p.use_count() 返回与p共享的对象智能指针数量
  p.unique() 若p.use_const为1， true， 否则 false
  ```

  ```cpp
  shared_ptr<int> p3 = make_shared<int>(42);
  shared_ptr<string> p4 = make_shared<string>(10,'9');
  shared_ptr<int> p5 = make_shared<int>();
  ```

  