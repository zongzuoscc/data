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
int pos1[maxn], pos2[maxn];
int a1[maxn], a2[maxn];
int L[maxn], size[maxn], R[maxn];
bool book = false;
  
void dfs(int l, int r) {
    if (l >= r)
        return;
    int root = a1[l];
    int lroot = a1[l + 1];
    int rroot = a2[pos2[root] - 1];
    if (lroot == rroot) {
        R[root] = rroot;
        book = true;
        dfs(l + 1, r);
        return;
    }
    int lsize = pos1[rroot] - pos1[lroot];
    L[root] = lroot;
    R[root] = rroot;
    dfs(l + 1, l + lsize);
    dfs(l + lsize + 1, r);
}
  
void dfs3(int now) {
    if (L[now])
        dfs3(L[now]);
    cout << now << " ";
    if (R[now])
        dfs3(R[now]);
    if (now == a1[1])
        cout << endl;
}
  
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        size[i] = 1;
        cin >> a1[i];
        pos1[a1[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a2[i];
        pos2[a2[i]] = i;
    }
  
    dfs(1, n);
    if (book)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    dfs3(a1[1]);
  
    return 0;
}