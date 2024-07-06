//这题和后根本质差不多

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

const int MAX_NODES = 26; // 最大节点数，26个大写字母
vector<int> tree[MAX_NODES]; // 存储树的邻接表
bool hasParent[MAX_NODES]; // 标记节点是否有父节点
// bool visited[MAX_NODES]; // 标记节点是否访问过

void postorderTraversal(int node) //输出后根遍历
{
    for (int child : tree[node]) 
    {
        postorderTraversal(child);
    }
    cout << (char)(node + 'A') << " ";
}

void preorderTraversal(int node) //输出先根遍历
{
    cout << (char)(node + 'A') << " ";
    for (int child : tree[node]) 
    {
        preorderTraversal(child);
    }
}
//后根遍历时先递归再输出
//先根遍历是先输出再递归
int main() 
{
    memset(hasParent, false, sizeof(hasParent));
    // memset(visited, false, sizeof(visited));
    
    char parent, child;
    while (cin >> parent >> child) 
    {
        int p = parent - 'A';
        int c = child - 'A';
        tree[p].push_back(c);
        hasParent[c] = true;
    }
    
    // 找到根节点
    int root = -1;
    for (int i = 0; i < MAX_NODES; i++) 
    {
        if (!hasParent[i] && !tree[i].empty()) 
        {
            root = i;
            break;
        }
    }
    
    if (root != -1) 
    {
        // 输出先根遍历
        preorderTraversal(root);
        cout << endl;
        // 输出后根遍历
        //postorderTraversal(root);
        //cout << endl;
    }
    return 0;
}
