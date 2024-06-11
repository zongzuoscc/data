// 上体育课的时候，老师已经把班级同学排成了两个队列，而且每个队列都是按照从底到高排好队，
// 现在需要把两个队列合并，合并后需要保证还是从低到高排列。合并队列，你能编程实现吗？
// 第1行为n，表示开始排成的每个队列的长度。第2、3行是代表从小到大的n个整数，每行的整数间有一个空格间隔。
// 输出占一行，为从小到大的整数，每个整数间间隔一个空格。

//考察了简单的二路归并，相较于归并排序，这已经很简单了
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) 
    {
        cin >> b[i];
    }

    int i = 0, j = 0;
    vector<int> result;
    while (i < n && j < n) 
    {
        if (a[i] <= b[j]) 
        {
            result.push_back(a[i++]);
        } 
        else 
        {
            result.push_back(b[j++]);
        }
    }

    while (i < n) 
    {
        result.push_back(a[i++]);
    }
    while (j < n) 
    {
        result.push_back(b[j++]);
    }

    for (int k = 0; k < 2 * n; k++) 
    {
        cout << result[k] << " ";
    }
    cout << endl;

    return 0;
}
