#include <iostream>
#include <algorithm>
using namespace std;
const int N=10010;
int find(int a[],int n){
    for(int i=0;i<n;i++){
        while (a[i] > 0 && a[i] <= n && a[a[i] - 1] != a[i]){
            // 交换 a[i] 和 a[a[i] - 1]
            swap(a[i], a[a[i] - 1]);
        }
    }
    // 再次遍历数组，找到第一个不在正确位置上的正整数
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            return i + 1;
        }
    }
    // 如果所有正整数都在正确的位置上，返回 n + 1
    return n + 1;
}
int main(){
    int n;
    int a[N];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<find(a,n)<<endl;
    return 0;
}