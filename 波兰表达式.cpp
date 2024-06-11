// 波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的波兰表示法为+ 2 3。
// 波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，
// 例如(2 + 3) * 4的波兰表示法为* + 2 3 4。本题求解波兰表达式的值，其中运算符包括+ - * /四个。
// 输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
// 输出为一行，表达式的值(保留6位小数)。

//这题采用了递归的思想 主要是很难想到要用递归来做，只要想到了，代码部分相对好写
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iomanip>
using namespace std;
const int N=100010;
char s[N];
double ans;
double calculate()
{
    // 这里的 cin >> s 会从输入中读取一个单词（以空格或换行符分隔），
    // 这意味着无论输入的是操作符还是操作数，都会被正确读取。
    // 例如，当输入数字 23 时，整个数字会被读取到 s 中，
    // 而不必担心数字的长度（只要在数组 s 的大小 N 范围内，并且这里的N开的范围足够大）。
    // 当递归调用 calculate() 时，新输入的字符会直接覆盖掉 s 中原来存储的内容。

    cin>>s;
    switch(s[0])
    {
        //这里的switch语法是将5种情况做讨论 当是加减乘除时 就递归运算（可以设置断点自己调试看是如何进行递归的）
        //当是数字时，就将字符转化为浮点型
        case '+':ans=calculate()+calculate();break;
        case '-':ans=calculate()-calculate();break;
        case '*':ans=calculate()*calculate();break;
        case '/':ans=calculate()/calculate();break;
        default :ans=atof(s);//atoi是c++中的一个函数 可以将字符串转化为浮点型 和stoi同理
    }
    return ans;
}
int main()
{
    printf("%.6lf",calculate());//这里是c的输出 用c++输出的话就用iomanip头文件中的函数 
    //cout<<fixed<<setprecision(6)<<calculate()<<endl;和上面同理 只不过上面短一点
    cout<<endl;
    return 0;
}
