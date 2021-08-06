/*
名称空间是为了防止函数名相同导致冲突,对于std空间，既可以使用using指令全部包括，也可以只包括一部分函数。
类似于python中 import 和 from...import...
using namespace std;
using std::cout;
using std::cin;
using std::endl;
这句编译指令放在不同的位置，作用域也不同：
    放在最前面，所有的函数都可以使用std中的函数
    放在main()函数中，只有main可以访问
    在别的函数中，可以使用 using std::cout 单独包含一部分。
    或者直接不用using，在需要使用std函数的地方，写 std::函数名
*/

/*
cout是一个预定义的输出对象，
<<是插入运算符，
cout<<string 是将一个字符串插入到输出流中。
*/

/*
一行代码中不可分割的元素叫标记（token）,必须用空白(包括空格，制表符，回车)将标记分割开。
括号和逗号不需要用空白分割开。
*/