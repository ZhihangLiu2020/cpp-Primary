#include "Queue.h"
//对于const成员变量，初始化必须使用如下语法，即初始化列表：变量名(值)
Queue::Queue(int qs):qsize(qs)
{
    front=rear=nullptr;
    items=0;
}
/*
//非const成员变量，也可以使用这种语法。下面的构造函数和上门是等效的。这种格式只能用于构造函数
Queue::Queue(int qs):qsize(qs),front(nullptr),rear(nullptr),items(0)
{

}
*/

bool Queue::isFull() const
{
    return items==qsize;
}

bool Queue::isEmpty() const
{
    return items==0;
}

int Queue::queueCount() const
{
    return items;
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

void Customer::set(long when)
{
    using namespace std;
    processtime = std::rand()%3+1;
    arrive = when;
}