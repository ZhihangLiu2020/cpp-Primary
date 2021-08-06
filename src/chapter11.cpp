/*
使用类

运算符重载：
    语法： operatorop(argument-list)
    例如： operator+(class a,class b)
          operator*()
          operator<<(ostream a,class b)
          
          使用友元函数实现重载，形式为 operator<<(ostream a,class b)，调用时，会转换成：
          a << b
          使用成员函数实现重载，形式为 operator+(class b),调用时：
          a.operator+(b)
    
    重载后的优先级不变。
    不能创造新运算符。
    不能重载下列运算符：
        sizeof
        .
        ::
        ?:
    一般来说成员变量是private的，因此能够访问类成员变量的要么是 成员函数，要么是 友元函数。
    两种方式都可以实现运算符重载。
友元：
    在为类重载二元运算符时，常常需要友元。
    c++限制private成员的访问权限，有时候太严格，因此需要使用友元：
    
    友元函数。类的友元函数是 非成员函数，但与成员函数访问权限相同。
        使用方法：在类中使用 friend 声明友元函数：friend void check();
        定义可写在类内，也可在类外写定义。友元函数不是类成员，因此在类外写不要使用 类:: 限定符写定义。而要按照普通函数写法。

    重载<<运算符
        1.满足输出单个：cout<<trip
        假设有一个Time类
        void operator<<(ostream &os, const Time &t)
        {
            os<<t.hours<<" "<<t.minutes<<endl;
        }
        重载完以后，就可以直接cout
        Time trip;
        cout<<trip;
        2.连续输出：cout << trip1 << trip2;
        因为<<要求左边是一个ostream对象，因此必须返回一个ostream对象，才能在右边继续使用<<输出
        ostream & operator<<(ostream &os, const Time &t)
        {
            os<<t.hours<<" "<<t.minutes;
            return os;
        }
*/

/*
#include <iostream>
using namespace std;
class Time{
private:
    int hours;
    int minutes;
public:
    //声明友元函数
    friend ostream& operator<<(ostream &os,const Time &t);
    //声明类成员函数
    void set(int a,int b);
};
//友元函数前不需要加 Time::
//重载<<运算符，cout是ostream类型
//把<<当初一个函数看，<<左边需要一个ostream类型对象，右边需要一个被打印的对象，因此接收2个参数。
ostream & operator<<(ostream &os,const Time &t)
{
        os<<t.hours<<" "<<t.minutes;
        return os;
}
//类成员函数前需要加 Time::
void Time::set(int a,int b)
{
        this->hours=a;
        this->minutes=b;
}

int main()
{
    Time trip1,trip2;
    trip1.set(1,2);
    trip2.set(3,4);
    cout<<trip1<<trip2;
}
*/