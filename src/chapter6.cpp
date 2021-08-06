/*
分支语句和逻辑运算符

字符库函数：
    在头文件<cctype>中定义了
    isalpha() 判断字母
    ispunct() 判断标点符号
    isspace() 判断空白
    isdigit() 判断数字0-9
    islower() 小写字母
    isupper() 大写字母

    
    iscntrl() 判断控制字符
    isgraph() 除空格之外的打印字符
    isprint() 可打印字符

    isalnum() 字母或数字

    tolower() 如果是大写字符，转换成小写，否则返回该参数
    toupper()

条件运算符 ?:
    可以用来代替if-else
    expression1 ? expression2:expression3

switch语句：
    switch只能处理整数类型，包括char
    一定记得加break,否则会把后续的都执行

文本文件输入输出：
    写文件必须包含：<fstream>, 它定义了 ofstream 类
    步骤：
    1.包含头文件
    2.定义ofstream对象
    3.使用对象调用 .open(“文件名”) 函数
    4.把对象当成cout对待
    5.调用.close()函数

    读文件必须包含 <fstream>, 它定义了 ifstream 类
    步骤：
    1.包含头文件
    2.定义ifstream对象
    3.使用对象调用.open(“文件名”)函数
    4.判断是否打开成功，调用 .is_open() 函数。（若不成功，可以用 exit(EXIT_FAILURE)函数退出,它定义在<cstdlib>）
    5.把对象当cin对待
    6.调用.close()函数


*/