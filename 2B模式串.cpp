//给你一个目标串，请查找在给目标串中是否存在模式串，存在就输出第一个模式串在目标串中出现的位置。
//占两行，第一行是目标串（长度小于1000），第二行为模式串（长度小于100）。
//输出模式串在目标串中出现的位置，即模式串匹配到目标串时第一个字符在目标串的位置（注意从1开始描述字符开始位置），不能匹配时输出0.

//暴力算法怎么做
//分析如何优化暴力算法
//s[N],比较长的串  即目标串
//p[M]，比较短的串  即模式串

//这个算法的时间复杂度是o(n)

//推荐一个讲解kmp算法的博客，讲的很详细   这是网址  https://blog.csdn.net/qq_43869106/article/details/128753527

#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
const int M=1000;
char s[N];//目标串
char p[M];//模式串
int ne[M];
int main()
{
    cin>>s;
    cin>>p;
    int m=strlen(s);//目标串长度
    int n=strlen(p);//模式串长度
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&p[i]!=p[j+1]) //如果说还么退到开始，并且，下一位仍然不匹配，那么
        {
            j=ne[j];
        }
        if(p[i]==p[j+1])//如果说匹配成功，那么j就前进一步 
        {
            j++;
        }
        ne[i]=j;//这里为什么要让ne[i]=j呢
    }


    // KMP匹配过程
    for (int i = 0, j = 0; i < m; i++) 
    {
        while (j > 0 && s[i] != p[j]) 
        {
            j = ne[j - 1];
        }
        if (s[i] == p[j]) 
        {
            j++;
        }
        if (j == n) 
        {
            // 匹配成功，输出第一个匹配的位置，从1开始计数
            cout << i - n + 2 << endl;//这里+2的原因是因为i从0开始计算，所以需要+2
            return 0;
        }
    }

    // 如果没有匹配成功  才会执行下面这两句，因为如果成功执行那么，已经结束了程序
    cout << 0 << endl;
    return 0;
}
/*

由于我们没有学kmp算法，所以说在oj上面，采用暴力算法也可以ac，那么我们在编写的时候就直接用暴力算法就好了，方便理解和记忆

#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
const int M=10010;
char s[N];//目标串
char p[M];//模式串
int main()
{
    cin>>s;
    cin>>p;
    int m=strlen(s);
    int n=strlen(p);
    for (int i = 0; i <= m - n; i++) 
    { // 遍历目标串
        bool found = true;
        for (int j = 0; j < n; j++) 
        { // 遍历模式串
            if (s[i + j] != p[j]) 
            { // 如果有不匹配的字符
                found = false;
                break;
            }
        }
        if (found) 
        { // 如果找到匹配
            cout << i + 1 << endl; // 输出位置（从1开始）
            return 0;
        }
    }
    cout << 0 << endl; // 没有找到匹配，输出0
    return 0;
}
*/