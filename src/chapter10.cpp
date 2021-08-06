/*
对象和类

    类型是什么
        定义变量时，会指定其类型，完成了：
        1.决定数据对象需要的内存数量
        2.决定如何解释内存中的位
        3.决定可使用数据对象完成的操作和方法
        对内置类型来说，这些信息被内置到编译器中。用户自定义的类，就要自己提供这些信息。
        一般的，类声明写在头文件中，类成员定义写在源文件中。
        
        //stock.h 头文件，类接口
        #include string
        class Stock{
        private:
            std::string company;
            long shares;
            double total_value;
            double share_value;
            void set_tot(){ total_value = shares*share_value; }//写在类声明中的函数，会自动成为内联函数
        public:
            void buy(int num,double price);
            void sell(int num,double price);
        };

        //stock.cpp 源文件
        #include "stock.h"
        void Stock::buy(int num,double price)
        {
            shares+=num;
            share_value=price;
            set_tot();
        }

        类和结构的区别：结构体的默认访问类型是public，类默认是private

        定义位于类声明中的函数，都将成为内联函数。

        每个创建的类对象都有自己的存储空间，存储其内部变量和类成员，但同一个类的所有对象共享一组类方法。

    类的构造和析构函数
        构造函数和析构函数没有类型。
        Stock::Stock(string a,long b,double c){company=a;shares=b;share_value=c;};
        使用时，下面两种写法时等价的：
        Stock a=Stock("good",250,1.2);
        Stock a("good",250,1.2);

        析构函数没有参数。如果构造函数使用了new，则析构函数必须使用delete
        ~Stock(){};

        const成员函数：写在后面，这样表示 函数不会修改调用对象。
        void show() const;//声明
        void Stock::show() const {...}

    this指针
        指向调用成员函数的对象。

        在类中声明常量：需要使用static
            static const int month=12;




*/