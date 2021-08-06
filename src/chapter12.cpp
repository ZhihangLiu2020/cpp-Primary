/*
类和动态内存分配

不能在类声明中初始化静态成员变量！：
    这是因为声明只是描述如何分配内存，但并不实际分配内存。
    对于静态类成员，是单独存储的，不是对象的组成部分。要在类声明之外使用单独的语句来初始化。

各种技术
    1.重载<<运算符
    friend ostream &operator(ostream &os, class_name &t); 在类中声明友元函数
    ostream & operator<<(ostream &os, class_name &t)
    {
        os<<...;
        return os;
    }

    2.转换函数
        把单个值转换为类类型，需提供构造函数：class_name(type_name value);
        把类转换为其他类型，需提供成员函数：operator type_name();

实现队列
    c11支持类内初始化，即：
        class a
        {
            int mem1=10;
            const int mem2=20;
        };
        等价于：
        a:a():mem1(10),mem2(20)
        {

        }

*/

/*


//StringBad.h 有缺陷的string类
#include <iostream>
#ifndef STRINGBAD_H
#define STRINGBAD_H
class StringBad
{
private:
    char * str;//pointor to string
    int len;//length of string
    static int num_strings;//number of objects,属于类，可以记录创建的对象个数。不能在此处初始化。
public:
    StringBad(const char* s);//constructor
    StringBad();//constructor
    ~StringBad();//destructor

    friend std::ostream & operator<<(std::ostream &os,const StringBad &st);
};
#endif

//StringBad.cpp
#include <cstring>
#include "stringBad.h"
using std::cout;

int StringBad::num_strings = 0;//注意，不能在类声明中初始化静态成员变量
//拷贝构造
StringBad::StringBad(const char *s)
{
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    num_strings++;
    cout<<num_strings<<":\""<<str<<"\" object created\n";
}
//默认构造
StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str,"C++");
    num_strings++;
    cout<<num_strings<<":\""<<str<<"\" object created\n";
    
}
//析构函数
StringBad::~StringBad()
{
    cout<<"\""<<str<<"\" object deleted,";
    --num_strings;
    cout<<num_strings<<" left\n";
    delete [] str;
}


*/

/*
//设计队列类
//1.分许需求，队列需要满足的要求
//2.设计接口，即类声明
//3.实现接口，即类定义
typedef Customer Item;
//队列类
class Queue
{
    enum {Q_SIZE=10};
    struct Node{Item item;Node* next;};
private:
    //类成员变量
    Node* front;//队头指针
    Node* rear;//队尾指针
    int items;//当前队伍中元素个数
    const int qsize;//队最大元素个数
public:
    Queue(int qs=Q_SIZE);//构造函数
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const;
    bool enQueue(const Item &item);
    bool deQueue(Item &item);


};
//对于const成员变量，初始化必须使用如下语法，即初始化列表：变量名(值)
Queue::Queue(int qs):qsize(qs)
{
    front=rear=nullptr;
    items=0;
}
//非const成员变量，也可以使用这种语法。下面的构造函数和上门是等效的。这种格式只能用于构造函数
Queue::Queue(int qs):qsize(qs),front(nullptr),rear(nullptr),items(0)
{

}
//进队
bool Queue::enQueue(const Item &item)
{
    if (isFull())
    {
        return false;
    }
    Node* add=new Node;
    add->item=item;
    add->next=nullptr;
    items++;
    if(front==nullptr)//队为空
    {front=add;}
    else
    {rear->next=add;}
    rear=add;
    return true;
}
//出队
bool Queue::deQueue(Item &item)
{
    if(front==nullptr)
    {return false;}
    item=front->item;
    items--;
    Node* temp=front;
    front=front->next;
    delete temp;
    if(items==0)
    {rear=nullptr;}
    return true;
}
//析构函数
Queue::~Queue()
{
    Node* temp;
    while(front!=nullptr)
    {
        temp=front;
        front=front->next;
        delete temp;
    }
}

//顾客类
#include <cstdlib>//rand()函数需要这个库
class Customer
{
private:
    long arrive; //到达时间
    int processtime;//处理时间
public:
    Customer(){arrive=processtime=0;};
    void set(long when);//设置到达时间
    long when() const
    {return arrive;}
    int ptime() const
    {return processtime;}
};
void Customer::set(long when)
{
    using namespace std;
    processtime = std::rand()%3+1;
    arrive = when;
}
*/