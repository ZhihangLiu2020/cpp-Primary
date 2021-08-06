//bank.cpp 使用Queue接口
//和Queue.cpp一起编译
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Queue.h"
const int MIN_PER_HR = 60;//每小时60分钟

bool newCustormer(double x);


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));
    
    cout<<"案例学习：Bank\n";
    cout<<"输入队列最大长度： ";
    int qs;
    cin>>qs;
    Queue line(qs);

    cout<<"输入模拟时间(小时)： ";
    int hours;
    cin>>hours;

    long cyclelimit = hours * MIN_PER_HR;//运行次数

    cout<<"请输入每小时平均顾客人数： ";
    double perhour;
    cin>>perhour;
    double min_per_cust;//到达的平均间隔时间
    min_per_cust = MIN_PER_HR/perhour;//每位顾客平均用时

    Item temp;
    long turnaway = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for(int cycle=0;cycle < cyclelimit;cycle++)
    {
        if(newCustormer(min_per_cust))//有顾客来
        {
            if(line.isFull())
            {
                turnaway++;
            }
            else
            {
                customers++;
                temp.set(cycle);//cycle=到达时间
                line.enQueue(temp);
            }
        }
        if(wait_time<=0 && !line.isEmpty())
        {
            line.deQueue(temp);
            wait_time=temp.ptime();
            line_wait+=cycle-temp.when();
            served++;
        }
        if(wait_time>0)
        {
            wait_time--;
        }
        sum_line+=line.queueCount();
    }

    //报告结果
    if(customers>0)
    {
        cout<<"接收的顾客数量： "<<customers<<endl;
        cout<<"服务的顾客数量： "<<served<<endl;
        cout<<"队满赶走的顾客： "<<turnaway<<endl;
        cout<<"平均队伍长度： ";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<double(sum_line)/cyclelimit<<endl;
        cout<<"平均等待时间： "
            <<(double)line_wait/served<<endl;
    }
    else
    {
        cout<<"没有顾客\n";
    }
    cout<<"完毕\n";

    return 0;
}

bool newCustomer(double x)
{
    return (std::rand() * x / RAND_MAX<1);
}