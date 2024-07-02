//对于给定的正整数序列，按照每个数的十进制形式各个位上的数之和从大到小排序，各个位上的数和相同的按照本身大小排序，大的在前，小的在后。
//第一行 1 个整数 n,表示序列的大小。( 0 < n ≤ 1000) 第二行 n 个正整数，表示序列的每个数，每个数不大于 100000000。
//输出按照题目要求排序后的序列。
//输入样例
//6 
//17 26 9 13 88 22
//输出样例
//88 9 26 17 22 13
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 辅助函数：计算一个整数的各个位数之和
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// 比较函数，用于排序
bool compare(int a, int b) {
    int sumA = digitSum(a);
    int sumB = digitSum(b);

    if (sumA != sumB) {
        return sumA > sumB;
    } 
    else 
    {
        return a > b;
    }
}

int main() 
{
    int n;
    cin >> n;

    vector<int> numbers(n);

    // 读取输入
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // 排序
    sort(numbers.begin(), numbers.end(), compare);

    // 输出结果
    for (int i = 0; i < n; ++i) {
        cout << numbers[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sumnum(int a)
{
    int sum=0;
    while(a>0)
    {
        sum+=a%10;
        a/=10;
    }
    return sum;
}
bool cmp(int a,int b)//解题的关键，自己定义一种新的比较方式，让sort函数使用这种方式进行比较
{
    int suma=sumnum(a);
    int sumb=sumnum(b);
    if(suma!=sumb)//两个数的总和不相等，返回总和更大的
    {
        return suma>sumb;
    }
    else
    {
        return a>b;//否则返回原本的数字更大的
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end(),cmp);//sort函数，第三个参数是比较方式，如果不写的话默认是按照从小到大排序
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}