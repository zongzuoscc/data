// 输入
// 输入只有一行，包含一个字符串S，用来建立二叉树。保证S为合法的二叉树先序遍历字符串，节点内容只有大写字母，且S的长度不超过100。
// 输出
// 共有三行，每一行包含一串字符，表示分别按先序、中序、中序得出的节点内容，每个字母后输出一个空格。请注意行尾输出换行。

#include <iostream>
#include <cstring>
using namespace std;

// 树的节点定义
struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

// 全局变量用于记录当前处理到的字符位置
int idx = 0;

// 创建一棵树
TreeNode* createTree(const char* S, int len) {
    if (idx >= len || S[idx] == '\0') return nullptr;// 如果已经处理完所有字符或者遇到字符串结束符，返回空指针
    // 当前字符创建一个节点
    TreeNode* node = new TreeNode(S[idx++]);// 创建一个新节点，其值为当前字符，并递增idx
    // 判断是否有左子树和右子树
    if (idx < len && S[idx] != ' ') // 如果idx小于字符串长度并且下一个字符不是空格，则创建左子树
    {
        node->left = createTree(S, len);// 递归创建左子树
    } 
    else 
    {
        idx++;// 否则跳过空格，递增idx
    }

    if (idx < len && S[idx] != ' ') 
    {
        node->right = createTree(S, len);
    } 
    else 
    {
        idx++;
    }
    return node;//返回根节点
}

// 先序遍历
void preorderTraversal(TreeNode* node) 
{
    if (node == nullptr) return;
    cout << node->value << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// 中序遍历
void inorderTraversal(TreeNode* node) 
{
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->value << " ";
    inorderTraversal(node->right);
}

// 后序遍历
void postorderTraversal(TreeNode* node) 
{
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->value << " ";
}

int main() 
{
    char S[101]; // 假设输入的字符串长度不超过100
    cin.getline(S, 101); // 使用getline来读取整行字符串，包括空格
    TreeNode* root = createTree(S, strlen(S));
    preorderTraversal(root);
    cout << endl;
    inorderTraversal(root);
    cout << endl;
    //postorderTraversal(root);
    inorderTraversal(root);
    cout << endl;
    return 0;
}

// 以下为使用数组来存储树并实现先序中序输出的代码
// #include <iostream>
// #include <cstring>
// using namespace std;

// const int MAXN = 100;
// char tree[MAXN]; // 用于存储二叉树的字符数组
// bool exists[MAXN]; // 用于标记节点是否存在

// // 全局变量用于记录当前处理到的字符位置
// int idx = 0;

// // 创建一棵树，返回树的根节点在数组中的索引
// int createTreeArray(const char* S, int len, int currentIdx) {
//     if (idx >= len || S[idx] == '\0') return -1;
    
//     tree[currentIdx] = S[idx++];
//     exists[currentIdx] = true;
    
//     if (idx < len && S[idx] != ' ') {
//         createTreeArray(S, len, 2 * currentIdx + 1);
//     } else {
//         idx++;
//     }
    
//     if (idx < len && S[idx] != ' ') {
//         createTreeArray(S, len, 2 * currentIdx + 2);
//     } else {
//         idx++;
//     }
    
//     return currentIdx;
// }

// // 先序遍历
// void preorderTraversalArray(int currentIdx) {
//     if (!exists[currentIdx]) return;
//     cout << tree[currentIdx] << " ";
//     preorderTraversalArray(2 * currentIdx + 1);
//     preorderTraversalArray(2 * currentIdx + 2);
// }

// // 中序遍历
// void inorderTraversalArray(int currentIdx) {
//     if (!exists[currentIdx]) return;
//     inorderTraversalArray(2 * currentIdx + 1);
//     cout << tree[currentIdx] << " ";
//     inorderTraversalArray(2 * currentIdx + 2);
// }

// // 后序遍历
// void postorderTraversalArray(int currentIdx) {
//     if (!exists[currentIdx]) return;
//     postorderTraversalArray(2 * currentIdx + 1);
//     postorderTraversalArray(2 * currentIdx + 2);
//     cout << tree[currentIdx] << " ";
// }

// int main() {
//     char S[101];
//     cin.getline(S, 101);
//     memset(exists, 0, sizeof(exists)); // 初始化节点存在标记为false
//     createTreeArray(S, strlen(S), 0);
    
//     preorderTraversalArray(0);
//     cout << endl;
//     inorderTraversalArray(0);
//     cout << endl;
//     inorderTraversalArray(0);
//     cout << endl;
    
//     return 0;
// }
