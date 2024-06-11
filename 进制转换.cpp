// 编写程序演示把一个10进制整数转换为R进制的转换结果。
// 正整数N和R，空格分隔
// N是输入的十进制数，R需要转换的进制数，2<=R<=20
// 将10进制整数转换为R进制的转换结果，超过9的数字符号显示为A、B、C……Z等字母。
//和hdu oj的2031题一模一样
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string turn(int n,int r)
{
    string result="";
    bool negative=false;
    //这里是判断数字是不是负数，因为符号并不需要操作 ，所以只需要先把负数变成正数，
    //然后输出的时候单独输出一个负号就好了
    if(n<0)
    {
        negative=true;
        n=-n;
    }
    while (n> 0) {
        int remainder = n % r; // 求余数
        char digit; // 用于存储当前位的数字字符

        // 将余数转换为对应的字符表示
        if (remainder < 10) 
        {
            digit = remainder + '0'; // 如果余数小于10，直接使用对应的数字字符
        }
        else 
        {
            digit = remainder - 10 + 'A'; // 如果余数大于等于10，使用对应的字母表示
        }

        result = digit + result; // 将当前位的字符插入到结果字符串的最前面
        n /= r; // 更新N为除以R的结果
    }

    // 如果是负数，在结果字符串最前面添加负号
    if (negative) 
    {
        result = '-' + result;
    }

    return result;

}
int main()
{
    int n;//10进制的数字
    int r;//需要转换的进制
    while(cin>>n>>r)
    {
        cout<<turn(n,r)<<endl;
    }
    return 0;
}
