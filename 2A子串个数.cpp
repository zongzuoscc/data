//给你若干个字符串，请编程输出每个字符串的子串个数。
//若干个字符串，每个字符串占一行，字符串中不含空格，长度最大为1000。
//对应每一行的字符串，输出该字符串子串的个数。
// #include <iostream>
// #include <string>

// using namespace std;

// int countSubstrings(string s) 
// {
//     int n = s.length();
//     return n * (n + 1) / 2+1;
// }

// int main() {
//     string s;
//     while (cin>>s) 
//     {
//         cout << countSubstrings(s) << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int n=s.size();
        cout<<n*(n+1)/2+1<<endl;
    }
    return 0;
}