/*
处理数据
命名规则：以两个下划线或一个下划线+大写字母开头的，留给编译器使用。以一个下划线开头的，留给用作全局标识符。

//头文件<climits>定义了数据类型的最大值，可以用sizeof()查看数据类型的长度
#include <climits>
#include <iostream>
int main()
{
    int n_max = INT_MAX;
    std::cout<<sizeof(int)<<std::endl;
    std::cout<<n_max<<std::endl;
    return 0;
}

c++11初始化方式：打括号初始化器
    int a = {24};//也可以不加=
    int a{24};
    int a = {};//空的话默认为0
    int a{};

不同进制数据定义方式：
    int a = 42;
    int b = 0x42; //16进制
    int c = 042; //8进制
    cout<<dec; //修改显示格式为10进制（默认）
    cout<<hex; //修改输出格式为16进制
    cout<<oct; //修改输出格式为8进制

const限定符：
    1.创建常量并初始化
        const int Months = 12;

auto关键字声明变量：
    根据右侧表达式的类型，自动推断变量的类型
    只能用于单值的初始化，不能用于初始化列表。






*/
