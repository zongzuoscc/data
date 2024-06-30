#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n, sum, temp;
    vector<int> s;
    while(cin >> n)
    {
        sum = 0;
        for(int i = 0; i< n; ++i)
        {
            cin >> temp;
            s.push_back(temp);
        }
        int st = 0, ed = n;
        while(ed-st != 1)
        {
            sort(&s[st], &s[ed]);
            temp = s[st++] + s[st++];//这里是相当于s[st]+s[st+1]，执行完之后，st++,也就是将最小的两个加起来
            sum += temp;
            s.push_back(temp);
            ed++;//因为每次迭代都将temp加入了vector向量当中，所有要将s的末尾拓宽
        }
        cout << sum << endl;
        s.clear();//将vector存储的数据清除
    }
}