/*
循环和关系表达式

for循环：
    1.设置初始值
    2.执行测试
    3.执行循环体
    4.更新测试值
    每个表达式都有值！
    赋值表达式的值：为左侧成员的值。例如 a=4 ,这个表达式的值为4. b = {a=4}+3; //b就是7
        例如 while(n--){} ，n--其实就是 n=n-1，它的值就是n的值，所以可以作为循环测试条件

    c++11for循环：
        对容器类，
        double prices[5]={1.0,2.1,1.5,4.0,5.0};
        for(double x : prices)
        {
            ...
        }

while循环：
    1.执行测试
    2.执行循环体

利用系统时间进行延迟：
    #include <iostream>
    #include <ctime> //ctime头文件定义了 CLOCKS_PER_SEC 符号常量，clock()函数，clock_t 类型
    using namespace std;
    int main()
    {
        float secs = 5.0;
        clock_t delay = secs * CLOCKS_PER_SEC;//符号常量，表示每秒多少个系统时间
        clock_t start = clock();//获取当前系统时间，是clock_t类型

        while(clock()-start < delay)
        {
            ;
        }

        cout<<"its time"<<endl;
        return 0;
    }

*/

