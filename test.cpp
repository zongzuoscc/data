// 哈夫曼树，第一行输入一个数n，表示叶结点的个数。需要用这些叶结点生成哈夫曼树，
// 根据哈夫曼树的概念，这些结点有权值，即weight，题目需要输出所有叶子结点的路径长度与权值的乘积之和。
// 输入有多组数据。
// 每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=1000）。
// 输出权值。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,sum,temp;
    cin>>n;
    vector<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        s.push_back(temp);
    }
    int st=0,ed=n;
    while(ed-st!=1)
    {
        sort(&s[st],&s[ed]);
        temp=s[st++]+s[st++];
        sum+=temp;
        s.push_back(temp);
        ed++;
    }
    cout<<sum<<" ";
    s.clear();
    cout<<endl;
    return 0;
}