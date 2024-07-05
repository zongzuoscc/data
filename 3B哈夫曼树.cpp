// 哈夫曼树，第一行输入一个数n，表示叶结点的个数。需要用这些叶结点生成哈夫曼树，
// 根据哈夫曼树的概念，这些结点有权值，即weight，题目需要输出所有叶子结点的路径长度与权值的乘积之和。
// 输入有多组数据。
// 每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=1000）。
// 输出权值。
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n, sum, temp;
    vector<int> s;
    while(cin >> n)
    {
        sum = 0;
        for(int i = 0; i< n; ++i)
        {
            cin >> temp;
            s.push_back(temp);
        }
        int st = 0, ed = n;
        while(ed-st != 1)
        {
            sort(&s[st], &s[ed]);
            temp = s[st++] + s[st++];//这里是相当于s[st]+s[st+1]，执行完之后，st++,也就是将最小的两个加起来
            sum += temp;
            s.push_back(temp);
            ed++;//因为每次迭代都将temp加入了vector向量当中，所有要将s的末尾拓宽
        }
        cout << sum << endl;
        s.clear();//将vector存储的数据清除
    }
}