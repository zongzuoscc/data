// 输入两个整数的求和式，比如1+2=，输出求和式和对应结果。请编程实现。
// 一个求和式，形如a+b=。
// 输出求和式及对应结果。
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string expression;
    getline(cin,expression);
    size_t add=expression.find('+');//size_t是无符号整数类型
    size_t equal=expression.find('=');//用来存储find函数返回的位置  这里是存储位置的
    string n=expression.substr(0,add);//substr这个函数 前一个参数表示的是提取的开始位置
    string m=expression.substr(add+1,equal-1-add);// 第二个参数 不是结束的位置 而是提取字符的长度
    int a=stoi(n);//stoi是c++中的一个函数 可以将字符串转化为整型
    int b=stoi(m);
    int result = a+b;
    cout<<expression<<result<<endl;
    return 0;
}