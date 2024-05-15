#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int b[N];
int find(int a[], int n) 
{
    // 初始化数组 b，所有元素设置为 0
    memset(b, 0, sizeof(b));
    // 标记出现的正整数，并存储在 b 中
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] <= n) {
            b[a[i]] = a[i];
        }
    }
    // 找到第一个未标记的正整数
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            return i;
        }
    }
    //没找到说明目前的数组是紧密排列的，输出下一个正整数即可
    return n + 1;
}
int main(){
    int n;
    cin >> n;
    int a[N];
    for (int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    cout << find(a, n) << endl;
    return 0;
}
