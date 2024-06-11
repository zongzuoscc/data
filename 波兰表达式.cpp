// 波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的波兰表示法为+ 2 3。
// 波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，
// 例如(2 + 3) * 4的波兰表示法为* + 2 3 4。本题求解波兰表达式的值，其中运算符包括+ - * /四个。
// 输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
// 输出为一行，表达式的值(保留6位小数)。

//这题采用了递归的思想 主要是，很难想到要用递归来做，只要想到了，代码部分相对好写
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
char s[N];
double ans;
double calculate()
{
    cin>>s;
    switch(s[0]){
        case '+':ans=calculate()+calculate();break;
        case '-':ans=calculate()-calculate();break;
        case '*':ans=calculate()*calculate();break;
        case '/':ans=calculate()/calculate();break;
        default :ans=atof(s);//atoi是c++中的一个函数 可以将字符串转化为浮点型
    }
    return ans;
}
int main()
{
    printf("%.6lf",calculate());
    cout<<endl;
    return 0;
}
