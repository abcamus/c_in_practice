# S.O.L.I.D 原则

It is first proposed by Robert C. Martin. He is a famous software engineer, working on software development over 40 years. He is also a preacher of Agile Programming, Extreme Programming, author of 《Clean Code》.etc.

## 开闭原则: The Open Closed Principle(OCP)

> *A module should be open for extension but closed for modification*

对扩展开放，对修改封闭。不修改模块的代码来增加模块的功能，听起来有点不可思议，是不是？这是怎么做到的呢？抽象。

通过一些抽象技术来实现OCP原则。

举几个例子：

**Dynamic Polymorphism**

```cpp
// Logon, must be modified to be extended.
struct Modem 
{
	enum Type {hayes, courrier, ernie) type;
};
struct Hayes
{
	Modem::Type type;
	// Hayes related stuff
};
struct Courrier
{
	Modem::Type type;
	// Courrier related stuff
};
struct Ernie
{
	Modem::Type type;
	// Ernie related stuff
};
void LogOn(Modem& m, string& pno, string& user, string& pw)
{
	if (m.type == Modem::hayes)
		DialHayes((Hayes&)m, pno);
	else if (m.type == Modem::courrier)
		DialCourrier((Courrier&)m, pno);
	else if (m.type == Modem::ernie)
		DialErnie((Ernie&)m, pno)
	// ...you get the idea
}
```

每次需要新增modem或修改modem策略的时候，都要遍历if/else或者switch/case。

更糟糕的是，程序员会试图将选择的动作隐藏起来，比如：Hayes和Courrier。这让系统的维护变得更加困难，也更容易出错。

```cpp
if (modem.type == Modem::ernie)
	SendErnie((Ernie&)modem, c);
else
	SendHayes((Hayes&)modem, c);
```

怎么让LogOn这个方法不用修改就能支持新的Modem呢？

<img src="/home/camus/.config/Typora/typora-user-images/image-20221231125910892.png" alt="image-20221231125910892" style="zoom:50%;" />

```cpp
class Modem
{
public:
    virtual void Dial(const string& pno) = 0;
    virtual void Send(char) = 0;
    virtual char Recv() = 0;
    virtual void Hangup() = 0;
};

void LogOn(Modem& m, string& pno, string& user, string& pw)
{
    m.Dial(pno);
    // go on
}
```

**Static Polymorphism**

通过模板或者泛型也可以起到同样的效果。

```cpp
template <typename MODEM>
void LogOn(MODEM& m, string& pno, string& user, string& pw)
{
    m.Dial(pno);
    // go on
}
```



## 李氏替换: The Liskov Substitution Principle(LSP)

> subclasses should be substitutable for their base classes

<img src="/home/camus/.config/Typora/typora-user-images/image-20221231135448791.png" alt="image-20221231135448791" style="zoom:50%;" />

以上图为例,函数User使用Base类,把Base类替换成Derived类,User的行为不应该改变.

```cpp
void User(Base& b);

Derived d;
User(d);
```

看上去好像是显而易见的事情，其实还是有细微的地方需要考虑。

比如，我们都知道圆是椭圆的特殊情况，长轴等于短轴，椭圆就成了圆。

<img src="/home/camus/.config/Typora/typora-user-images/image-20221231142702701.png" alt="image-20221231142702701" style="zoom:50%;" />

<img src="/home/camus/.config/Typora/typora-user-images/image-20221231143154179.png" alt="image-20221231143154179" style="zoom:50%;" />

看似逻辑非常合理，在实现中并不如此。椭圆类型需要两个焦点和长轴的长度，然而定义一个圆只需要一个中点和半径。上面的继承逻辑关系，看上去就不合理了。

如果现实代码中有这样一个函数

```cpp
void f(Ellipse& e)
{
    Point a(-1,0);
    Point b(1,0);
    e.SetFoci(a,b);
    e.SetMajorAxis(3);
    assert(e.GetFocusA() == a);
    assert(e.GetFocusB() == b);
    assert(e.GetMajorAxis() == 3);
}
```

函数f如果传入Circle参数，SetFoci函数行为就必须改变。因此，这个函数是不可替换的。

一种丑陋的方法是，在f函数中增加if/else判断，比如

```cpp
void f(Ellipse& e)
{
    if (typeid(e) == typeid(Ellipse))
    {
        Point a(-1,0);
        Point b(1,0);
        e.SetFoci(a,b);
        e.SetMajorAxis(3);
        assert(e.GetFocusA() == a);
        assert(e.GetFocusB() == b);
        assert(e.GetMajorAxis() == 3);
    }
    else
    	throw NotAnEllipse(e);
}
```

但是这种方式又违背了OCP原则。李氏替换原则实质上是对Client如何使用类型的一种约定，违背李氏替换即违背了约定。

## 依赖倒置：The Dependency Inversion Priciple(DIP)

> Depend upon Abstractions. Do not depend upon concretions.

<img src="/home/camus/.config/Typora/typora-user-images/image-20221231150506344.png" alt="image-20221231150506344" style="zoom:50%;" />

一般开发过程中，总是上层模块依赖下层模块，如上图所示。这样的话，如果下层实现改变，上层模块不得不做对应的改变。如何极可能减少这种改变？这里就是依赖导致原则。

让上层模块依赖于抽象接口，下层模块实现抽象接口，这时候的依赖关系看上去像是下层依赖上层，而下层模块实现改变不会导致上层代码的改变。

<img src="/home/camus/.config/Typora/typora-user-images/image-20221231150959446.png" alt="image-20221231150959446" style="zoom:50%;" />

依赖倒置其实是一种非常严格的约束，它认为所有具体的东西都是易变的，不应该被依赖。

有一种常见的场景--对象创建，通常对象创建都需要依赖具体的类。一种优雅的解决方式为Abstract Factory。

## 接口隔离：The Interface Segregation Principle (ISP)

> Many client specific interfaces are better than one general purpose interface

在多个client使用一个class的场景下，为每个client实现接口好过使用一个通用的接口。

## 单一职责：Single Responsibility Principle(SRP)



## 参考资料

[1] Design Principles and Design Patterns. Robert C. Martin

[2] 
