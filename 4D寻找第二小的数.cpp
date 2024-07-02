// 求n个整数中第二小的数。
// 相同的整数看成一个数。比如，有5个数分别是1,1,3,4,5，那么第二小的数就是3。
// 输入包含多组测试数据。输入的第一行是一个整数C，表示有C组测试数据；
// 每组测试数据的第一行是一个整数n，表示本组测试数据有n个整数（2<=n<=10），接着一行是n个整数（每个数均小于100）。
// 为每组测试数据输出第二小的整数，如果不存在第二小的整数则输出“NO”，每组输出占一行。

//这道题不难，只需要用set就好了，也可以不用

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() 
{
    int C;
    cin >> C;
    while (C--) 
    {
        int n;
        cin >> n;
        set<int> nums;//建立一个集合，集合中无重复元素
        for (int i = 0; i < n; ++i) 
        {
            int num;
            cin >> num;
            nums.insert(num);
        }

        // 将集合中的元素转移到一个排序好的vector中
        vector<int> sortedNumbers(nums.begin(), nums.end());
        
        if (sortedNumbers.size() < 2) //如果数组元素个数小于2则证明没有第二小的元素
        {
            cout << "NO" << endl;
        } 
        else 
        {
            cout << sortedNumbers[1] << endl;//输出数组中第二个元素
        }
    }

    return 0;
}