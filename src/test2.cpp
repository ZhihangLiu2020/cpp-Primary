#include <iostream>
#include <set>
#include <vector>
using namespace std;

//携程第二题，包依赖

int main()
{
    char n;
    cin>>n;
    cin.get();//吸收换行符
    string s;
    vector<string>v={};
    set<char> st;
    st.insert(n);
    //这样写有问题，这样会无休止的读下去，只有遇到ctrl+D才能停止
    /*
    while(getline(cin,s))
        {
            if(s=="") break;
            v.push_back(s);
        }
    */

    //正确写法
    getline(cin,s);
    while(s!="")
    {
        v.push_back(s);
        getline(cin,s);
    }
    
    //segementation fault: 访问越界,因为使用了erase()
    while(true)
    {
        bool flag=false;
        //注意使用erase时，要小心
        for(auto i=v.begin();i!=v.end();)
        {
            for(auto it=st.begin();it!=st.end();it++)
            {
                //string.find()函数，找到返回下标，找不到返回string::npos
                if((*i).find(*it)!=string::npos)
                {
                    st.insert((*i)[0]);
                    //cout<<(*i)[0]<<endl;
                    //调用erase（）函数后，vector后面的元素会向前移位，形成新的容器，这样原来指向删除元素的迭代器（i）就失效了。
                    i=v.erase(i);//在erase后，i失效，并不是指向vector的下一个元素，i成了一个“野指针”。
                    i--;
                    flag=true;
                    break;
                }
            }
            i++;
        }
        if(flag==false) break;
    }
    //局部变量一定要初始化！！！
    int ans=0;
    //cout<<"st:"<<endl;
    for(auto it=st.begin();it!=st.end();it++)
    {
        if((*it)!=n) ans+=(*it)-'0';
        //cout<<*it<<endl;
    }
    cout<<ans<<endl;
    return 0;
}