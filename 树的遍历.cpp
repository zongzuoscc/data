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

#include <cstring>
#include <iostream>
using namespace std;
 
const int maxn = 40;
int pos1[maxn], pos2[maxn];// pos1 记录每个节点在前序遍历中的位置，pos2 记录每个节点在后序遍历中的位置
int preorder[maxn], postorder[maxn];// preorder 存储前序遍历序列，postorder 存储后序遍历序列
int L[maxn], size[maxn], R[maxn];// L 和 R 分别存储每个节点的左子节点和右子节点
bool notonly = false;//记录是否唯一
// 深度优先搜索，用于构建二叉树
void dfs(int l, int r) {
    if (l >= r)
        return;
    int root = preorder[l];// 当前子树的根节点
    int lroot = preorder[l + 1];// 左子树的根节点（前序遍历的下一个节点）
    int rroot = postorder[pos2[root] - 1];// 右子树的根节点（后序遍历中根节点的前一个节点）
    if (lroot == rroot) //如果左子树根节点和右子树根节点相同
    {
        R[root] = rroot;// 将其作为右子树根节点
        notonly = true;//说明不唯一
        dfs(l + 1, r);//递归处理剩余节点
        return;
    }
    int lsize = pos1[rroot] - pos1[lroot];// 计算左子树的大小 就是右子树节点开始的位置减去左子树节点开始的位置
    L[root] = lroot;// 记录左子树根节点
    R[root] = rroot;// 记录右子树根节点
    dfs(l + 1, l + lsize);//递归处理左子树
    dfs(l + lsize + 1, r);//递归处理右子树
}

//用于中序遍历
void dfsmid(int now)//now表示当前节点
{
    if (L[now])
        dfsmid(L[now]);//遍历左子树

    cout << now << " ";//输出当前节点，以及空格

    if (R[now])
        dfsmid(R[now]);//遍历右子树

    if (now == preorder[1])//如果是根节点那么换行
        cout << endl;
}

//关于先序，中序，后序遍历的代码部分，根据他们的名字就可以理解代码，
//先序就先输出节点 然后递归左子树 最后递归右子树
//中序就先递归左子树 然后输出节点 最后递归右子树
//后序就先递归左子树 然后递归右子树 最后输出节点
 
int main()
{
    int n;//节点个数
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        //size[i] = 1;
        cin >> preorder[i];//输入先序的序列
        pos1[preorder[i]] = i;//记录 先序节点的值 在后序序列中的位置
    }
    for (int i = 1; i <= n; i++) 
    {
        cin >> postorder[i];//输入后序的序列
        pos2[postorder[i]] = i;//记录 后序节点的值 在后序序列中的位置
    }
 
    dfs(1, n);//把树构建好 并计算出树是否唯一
    if (notonly)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    dfsmid(preorder[1]);//根据构建好的树输出中序遍历的序列
    for(int i=0;i<n;i++)
    {
        cout<<pos1[i]<<" ";
    }
    cout<<endl;
        for(int i=0;i<n;i++)
    {
        cout<<pos2[i]<<" ";
    }
    cout<<endl;
    return 0;
}