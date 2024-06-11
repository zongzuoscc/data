// n个人围成一圈，按1到n的顺序编号。从第一个人开始报数（从1到m报数），凡报到m的人退出圈子，问最后留下的是原来的第几号。
// 首先输入两个正整数n和m，n表示n个人围一个圈子（n>=2），m表示从1报数到m的人退出圈子（1=<m）。
// 最后剩下的人的编号。
#include <iostream>
using namespace std;
int josephus(int n,int m)
{
    int end=0;
    for(int i=2;i<=n;i++)
    {
        end=(end+m)%i;//这一步其实就是不断地将第m个人退出去
    }
    return end+1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<josephus(n,m)<<endl;
    return 0;
}