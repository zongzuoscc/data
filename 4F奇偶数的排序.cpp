// 给你10个正整数，其中5个奇数、5个偶数，先递减排奇数，然后再递增排偶数。请编程实现。
// 一行10个正整数（int类型范围）。
// 先递减排5个奇数，然后再递增排5个偶数，各个数之间有一个空格间隔。
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers(10);
    vector<int> odd_numbers;
    vector<int> even_numbers;

    // 读取10个正整数
    for (int i = 0; i < 10; ++i) {
        cin >> numbers[i];
    }

    // 分离奇数和偶数
    for (int i = 0; i < 10; ++i) {
        if (numbers[i] % 2 == 0) {
            even_numbers.push_back(numbers[i]);
        } else {
            odd_numbers.push_back(numbers[i]);
        }
    }

    // 对奇数进行递减排序
    sort(odd_numbers.begin(), odd_numbers.end(), greater<int>());

    // 对偶数进行递增排序
    sort(even_numbers.begin(), even_numbers.end());

    // 输出排序结果
    for (size_t i = 0; i < odd_numbers.size(); ++i) {
        cout << odd_numbers[i];
        if (i < odd_numbers.size() - 1 || !even_numbers.empty()) {
            cout << " ";
        }
    }

    for (size_t i = 0; i < even_numbers.size(); ++i) {
        cout << even_numbers[i];
        if (i < even_numbers.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int odd_numbers[5];//存奇数
    int even_numbers[5];//存偶数
    int j=0,k=0;
    for(int i=0;i<10;i++)
    {
        int number;
        cin>>number;
        if(number%2==0)
        {
            even_numbers[j++]=number;
        }
        else
        {
            odd_numbers[k++]=number;
        }
    }
    sort(odd_numbers,odd_numbers+5,greater<int>());
    sort(even_numbers,even_numbers+5);//这里的sort前两个参数，由于我们没有用vector，而是用的数组，所以采用的是第一个变量是数组命
    //第二个变量是数组名加数组长度（其实就是地址）
    for(int i=0;i<5;i++)
    {
        cout<<odd_numbers[i]<<" ";
    }
    for(int i=0;i<5;i++)
    {
        cout<<even_numbers[i]<<" ";
    }
    return 0;
}