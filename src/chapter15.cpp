/*
友元、异常和其他


友元类
    有些不适合做公有继承和私有继承的，可以声明为友元类，比如电视机和遥控器。
    class A{
    public:
        friend class B;
    }
    把B声明为A的友元类，B就可以直接访问A的私有和保护成员。

嵌套类
    在一个类中，声明另一个类。
    对类进行嵌套通常是为了帮助实现另一个类，并避免名称冲突。
    嵌套类的作用域为 声明它的类，可见域取决于它声明在public还是private；如果声明在public，那么外界可以使用它，但是要加类限定符
    class Queue
    {
    public:
        class Node
        {
        public:
            int val;
            Node * next;
        }
    }
    



*/