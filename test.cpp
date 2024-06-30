// 新年快到了，天勤准备搞一个聚会，
// 已经知道现有会员N人，把会员从1到N编号，其中会长的号码是N号，
// 凡是和会长是老朋友的，那么该会员的号码肯定和N有大于1的公约数，否则都是新朋友，
// 现在会长想知道究竟有几个新朋友？请你编程序帮会长计算出来。
//第一行是测试数据的组数CN（Case number，1<CN<10000），接着有CN行正整数N（1<n<32768），表示会员人数
//对于每一个N，输出一行新朋友的人数，这样共有CN行输出。
#include <iostream>
using namespace std;
const int N=32778;
int cn;
int primes[N+10];
void shai()//注意是void类型才可以，int 类型会出错
{
    for(int i=0;i<=N;i++)
    {
        primes[i]=i;//初始化primes数组，这个数组里面存储质数个数,一开始就是假设所有的数都是质数
    }
    for(int i=2;i<N;i++)
    {
        if(primes[i]==i)
        {
            for(int j=i;j<=N;j+=i)
            {
                primes[j]=primes[j]/i*(i-1);//这行是解题的关键  牢记
            }
        }
    }
}
int main()
{
    cin>>cn;
    shai();
    while(cn--)
    {
        int n;
        cin>>n;
        cout<<primes[n]<<endl;
    }
    return 0;
}