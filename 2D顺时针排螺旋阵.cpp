// 给你一个N行N列的方格矩阵，从外圈按顺时针依次填写自然数，这会构成一个螺旋阵，你能编程实现吗？
// 比如5行5列的情况如下：
// 1 2 3 4 5
// 16 17 18 19 6
// 15 24 25 20 7
// 14 23 22 21 8
// 13 12 11 10 9
//输入 输入一个正整数数N（N<100）。
//输出 输出符合题意的螺旋阵。

// #include <iostream>
// #include <vector>
// using namespace std;

// void Matrix(int n)
// {
//     vector<vector<int>> matrix(n, vector<int>(n, 0));
//     int num = 1;
//     int top = 0, bottom = n - 1;
//     int left = 0, right = n - 1;

//     while (num <= n * n)
//     {
//         // 从左到右填充上边
//         for (int i = left; i <= right; i++) 
//         {
//             matrix[top][i] = num++;
//         }
//         top++; // 上边界下移

//         // 从上到下填充右边
//         for (int i = top; i <= bottom; i++)
//         {
//             matrix[i][right] = num++;
//         }
//         right--; // 右边界左移

//         // 从右到左填充下边
//         for (int i = right; i >= left; i--)
//         {
//             matrix[bottom][i] = num++;
//         }
//         bottom--; // 下边界上移

//         // 从下到上填充左边
//         for (int i = bottom; i >= top; --i)
//         {
//             matrix[i][left] = num++;
//         }
//         left++; // 左边界右移
//     }

//     // 输出矩阵
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() 
// {
//     int n;
//     cin >> n;
//     Matrix(n);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int matrix[n][n];
    int num=1;
    int left=0,right=n-1,top=0,bottom=n-1;
    while(num<=n*n)
    {
        for(int i=left;i<=right;i++)
        {
            matrix[top][i]=num++;
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            matrix[i][right]=num++;
        }
        right--;
        for(int i=right;i>=left;i--)
        {
            matrix[bottom][i]=num++;
        }
        bottom--;
        for(int i=bottom;i>=top;i--)
        {
            matrix[i][left]=num++;
        }
        left++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}