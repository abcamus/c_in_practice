# S.O.L.I.D principles

It is first proposed by Robert C. Martin. He is a famous software engineer, working on software development over 40 years. He is also a preacher of Agile Programming, Extreme Programming, author of 《Clean Code》.etc.

## O: The Open Closed Principle(OCP)

> *A module should be open for extension but closed for modification*

对扩展开放，对修改封闭。不修改模块的代码来增加模块的功能，听起来有点不可思议，是不是？这是怎么做到的呢？抽象。

通过一些抽象技术来实现OCP原则。



举几个例子：

动态多态

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

```cpp
class Modem
{
public:
```



## 