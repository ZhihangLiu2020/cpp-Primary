#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

//携程第一题，输入一个数n，1<=n<=12，
//n=1,R
//n=2,GRR,就是在上次的字母左边加一个G,右边加一个R

struct TreeNode
{
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string val)
    {
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
//生成树
void makeTree(TreeNode *root,int m)
{
    if(m==1)
        {
            return;
        }
    root->left=new TreeNode("G");
    root->right=new TreeNode("R");
    makeTree(root->left,m-1);
    makeTree(root->right,m-1);
    
}

void inorder(TreeNode* root,string &ans)
{
    if(root!=nullptr)
        {
            inorder(root->left,ans);
            ans+=root->val;
            inorder(root->right,ans);
        }
}

string buildingHouse(string n) {
    int t=0;
    if(n.size()==1)
    {
        t=atoi(n.c_str());
    }
    if(n.size()==2)
    {
        t=(n[0]-'0')*10+n[1]-'0';
    }
    if(t==1)
        {
            return "R";
        }
    if(t==2)
        {
            return "GRR";
        }
    //生成一棵树，然后先序遍历
    TreeNode* root=new TreeNode("R");
    
    makeTree(root,t);
    string ans;
    inorder(root,ans);
    return ans;

}
/******************************结束写代码******************************/
//判断是不是数字
bool judgeNum(string &s)
{
    for(int i=0;i<s.size();i++)
        {
            if(!isdigit(s[i]))
                {
                    return false;
                }
        }
    return true;
}
//判断是不是在1-12之间
bool judgeLim(string &s)
{
    if(s.size()==1)
    {
        if(s[0]-'0'>=1 && s[0]-'0'<=12)
        {
            return true;
        }
    }
    if(s.size()==2)
    {
        int temp=(s[0]-'0')*10+s[1]-'0';
        if(temp<=12)
        {
            return true;
        }
    }
    return false;
}
//判断是不是负数
bool judgeNeg(string &s)
{
    if(s[0]=='-')
    {
        for(int i=1;i<s.size();i++)
        {
            if(!isdigit(s[i]))
                {
                    return false;
                }
        }
        return true;
    }
    return false;
}

int main() {
    string res;

    string _n;
    getline(cin, _n);
    if(judgeNeg(_n))
    {
        cout<<"O"<<endl;
        return 0;
    }
    if(!judgeNum(_n))
    {
        cout<<"N"<<endl;
        return 0;
    }
    
    if(!judgeLim(_n))
    {
        cout<<"O"<<endl;
        return 0;
    }
    res = buildingHouse(_n);
    cout << res << endl;
    
    return 0;

}
