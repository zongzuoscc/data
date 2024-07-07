// 假设二叉树中的所有键值都是不同的正整数。唯一的二元树可以通过给定的后序和顺序遍历序列，
//或前序和顺序遍历序列来确定。但是，如果仅给出后序和前序遍历序列，则相应的树可能不再是唯一的。
// 现在给出一对后序和前序遍历序列，您应该输出树的相应的中序遍历序列。如果树不是唯一的，只需输出其中任何一个。
//每个输入文件包含一个测试用例。对于每种情况，第一行给出正整数N（≤30），即二叉树中的节点总数。
//第二行给出预订序列，第三行给出后序序列。一行中的所有数字都用空格分隔。
// 对于每个测试用例，如果树是唯一的，则首先是行中的Yes，否则是No。然后在下一行中打印相应二叉树的中序遍历序列。
//如果解决方案不是唯一的，那么任何答案都可以。保证至少存在一种解决方案。一行中的所有数字必须用一个空格分隔，并且行的末尾不能有额外的空格。

// C题经过测试，在oj上并非为特殊判题，虽然题目说不唯一输出任意一个，经实测，树不唯一时，将子树优先放在右支，
// 即输入为 
// 3
// 3 2 1
// 1 2 3
// 时，输出应为1 2 3
// 输出为3 2 1时不会给判对！
// 如果树唯一那么还是以先左子树再右子树的顺序
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
  
const int maxn = 40;
int pos1[maxn];//记录先序序列中节点所在的位置
int pos2[maxn];//记录后序序列中节点所在的位置
int a1[maxn];//记录输入的先序序列
int a2[maxn];//记录输入的后序序列
int L[maxn];//存储节点i的左子节点
int R[maxn];//存储节点i的右子节点
bool notonly = false;
  
void dfs(int l, int r) 
{
    if (l >= r)
        return;
    int root = a1[l];//根节点赋值为先序序列的第一个节点
    int lroot = a1[l + 1];//左子树的根节点
    int rroot = a2[pos2[root] - 1];//右子树的根节点
    if (lroot == rroot) {//若左右子树根节点相同
        R[root] = rroot;//令根节点的右子树的根节点为这个重合的节点
        notonly = true;//把树标记为不唯一
        dfs(l + 1, r);//递归处理
        return;
    }
    int lsize = pos1[rroot] - pos1[lroot];//左子树的大小
    L[root] = lroot;
    R[root] = rroot;
    dfs(l + 1, l + lsize);//递归处理左子树
    dfs(l + lsize + 1, r);//递归处理右子树
}
  
void inorder(int now) 
{
    if (L[now])
        inorder(L[now]);
    cout << now << " ";
    if (R[now])
        inorder(R[now]);
    if (now == a1[1])
        cout << endl;
}
  
int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a1[i];
        pos1[a1[i]] = i;
    }
    for (int i = 1; i <= n; i++) 
    {
        cin >> a2[i];
        pos2[a2[i]] = i;
    }
  
    dfs(1, n);
    if (notonly)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    inorder(a1[1]);

    return 0;
}