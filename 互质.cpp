// 给你一个正整数n，请问有多少个比n小的且与n互质的正整数？
// 两个整数互质的意思是，这两个整数没有比1大的公约数。
//输入包含多组测试数据。每组输入是一个正整数n（n<=1000000000）。当n=0时，输入结束。
//对于每组输入，输出比n小的且与n互质的正整数个数。
#include <iostream>
using namespace std;
long long n;
int main()
{
    while(cin>>n&&n!=0)
    {
        int res=n;
        //以下为分解质因数
        for(int i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                res=res/i*(i-1);//res*(1-1/n);前面的语句为这一句的化简
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }
        if(n>1)//说明n有一个大于1 的质因子  再把质因子除去就好了
        {
            res=res/n*(n-1);
        }
        cout<<res<<endl;
    }
    return 0;
}