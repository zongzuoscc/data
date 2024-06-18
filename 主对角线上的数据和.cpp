//在一个N行N列的方阵(或称N阶方阵)中，从左上角到右下角这一斜线上有N个数据元素，
//这个斜线称为方阵的主对角线。给你一个方阵，请求方阵主对角线上数据的和。
//第一行是N（N<100），表示下边是一个N阶方阵。接下来N行N列用空格间隔放置正整数（int型）。
//N阶方阵主对角线上数据的和。
#include <iostream>
using namespace std;
const int N=101;
int matrix[N][N];
int n,ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=matrix[i][i];
    }
    cout<<ans<<endl;
    return 0;
}