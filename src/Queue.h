
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




