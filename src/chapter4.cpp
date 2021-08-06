/*
复合类型
数组：
    只能在定义时初始化，以后就不可以使用{}初始化了，只能使用下标赋值。
    也不能让一个数组等于另一个数组。
    如果只对一部分元素初始化，剩下的会被赋值为0。
    int a[4]={1,2,3,4}; //ok

    int b[4];
    b[4]={1,2,3,4}; //not allowed
    
    b=a; //not allowed

    int c[4]={};//c++11允许的初始化，所有元素都为0
    
字符串：
    char数组的最后一位必须是'\0',才表示字符串。
    cin使用空白（空格，制表符，换行）来决定字符串结束的位置。
    cin.getline(char a[],int n) 读取n-1个字符到字符数组a,并且补一个'\0'
    cin.getline()遇到换行符才停止，并且丢弃换行符。

    cin.get(char a[],int n)
    cin.get()会把换行符保留在输入流中，因此要用一个不带参数的cin.get()吸收换行符。

    对于string对象，使用 getline(cin,str) 来读取并存入str中。

    c++11字符串初始化：
        string s = {"good day"}
    c++11原始字符串：
        使用R"()"把字符串包住，输出就是括号内的字面内容，（）叫做界定符，可以自定义

结构：struct
    struct person{
        int age;
        string name;
    };
    person p;
    可以用.来访问struct对象内的成员,p.name; p.age;
    结构初始化：person p = {25,"louis"};//=可以省略
              person p = {}; //什么都不写，那么所有成员会被初始化为0

共用体：union
    union one{
        int int_val;
        long long_val;
        double double_val;
    };
    共用体和结构体的区别是，共用体在同一时间只能存储一种类型，它的长度为其中最大成员的长度。

枚举类型：使用enum工具来定义
    enum color{red,green,orange,blue};
    color成为类型名称，可以定义枚举变量；red,green,成为符号常量，对应的值为0,1,...
    color picture;
    picture = green;//可以
    picture = 1;//不可以，int类型不可以转换成枚举
    int a;
    a = red +1;//可以，枚举可以转换成int类型

指针和自由存储空间：
    &：取地址符
    *：解引用符
    声明指针：int* p;  由于*运算符必须用于指针前，所以p是一个指针！
    *p是int类型，int* 是复合类型，是指向int的指针。

    new和delete：
    delete是释放指针指向的内存空间，而不是删除指针本身，该指针还可以用。
    要配对使用。
    不要尝试释放已经释放的内存块。
    不能用delete来释放声明变量获得的内存，它只能释放new出来的内存。
    使用delete[]来释放new出来的数组。

    int *p = new int[10];
    p[0]=1;//使用下标访问数组元素
    p[1]=2;
    delete [] p;

    数组名：一般被视为首元素的地址
    int a[10];
    cout<< a <<endl;//a[0]的地址
    cout<< &a <<endl;//a数组的地址
    从数值上来讲这俩是一样的，但是a+1是将地址+4，而&a+1是将地址+40，也就是整个数组的地址长度。

    .和->的区别：
        .用于变量名，访问其成员；person p; p.name="zh";
        ->用于指针，访问其成员。person *p = new person; p->name="zh";
                            也可以 (*p).name="zh";由于运算符优先级，必须加括号

存储类型：存在时间不一样
    1.自动存储
        在函数内部定义的常规变量（局部变量）随函数结束而销毁。使用自动存储空间，也就是栈。
    2.静态存储
        是整个程序执行期间都存在的存储方式。有两种：1.在函数外面定义 2.使用static关键字
    3.动态存储
        使用new和delete管理的自由存储区（堆），存活时间不受函数和程序限制。

数组和vector、array：
    vector模板类：vector<int> a1[10]; 存储在堆区
    array模板累：array<int,10> a2; 存储在栈区
    数组存储在栈区，不可以使用=来连接两个数组。
    a1[-2]=0 表示找到a1指向的地方，向前移动2个int长度，赋值为0。这就是数组越界。
    防止越界的方法是，使用成员函数at(), a1.at(1)=0; a2.at(3)=0;






*/
