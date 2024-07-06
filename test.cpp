// 已知一颗树的节点间关系，请编程实现该树的先根遍历。
//若干行，每行描述了一组双亲节点和孩子节点的关系序偶对（每个节点用不同的大写字母表示，节点小于26个）。且树的度小于5。
// 该树的先根遍历序列，序列中每个字母用空格隔开。
//输入
// B E
// B F
// A B
// A C
//输出  A B E F C
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_NODE=26;
vector<int> tree[MAX_NODE];//邻接表存树
bool hasParent[MAX_NODE];//看每个节点是否有父节点

void preorder(int node)
{
    cout<<(char)(node+'A')<<" ";
    for(int i=0;i<tree[node].size();i++)
    {
        int child=tree[node][i];
        preorder(child);
    }
}

void postorder(int node)
{
    for(int i=0;i<tree[node].size();i++)
    {
        int child=tree[node][i];
        postorder(child);
    }
    cout<<(char)(node+'A')<<" ";
}

int main()
{
    char parent,child;
    memset(hasParent,false,sizeof hasParent);
    while(cin>>parent>>child)
    {
        int p=parent-'A';
        int c=child-'A';
        tree[p].push_back(c);
        hasParent[c]=true;
    }
    int root=-1;
    for(int i=0;i<MAX_NODE;i++)
    {
        if(!hasParent[i]&&!tree[i].empty())
        {
            root=i;
            break;
        }
    }
    if(root!=-1)
    {
        preorder(root);
        cout<<endl;
    }
    return 0;
}