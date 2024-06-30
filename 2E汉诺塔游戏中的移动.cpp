//有三根标为A,B,C的柱子，A柱子上从上到下按金字塔状依次叠放着n个半径从1厘米到n厘米的的圆盘，
//要把A上的所有盘子移动到柱子C上，中间可以临时放在B上，
//但每次移动每一根柱子上都不能出现大盘子在小盘子上方的情况，要求用最少的移动次数完成，请编程模拟每次移动。
//输入 占一行，为整数n（n<64），表示盘子数。
//输出 把A上的所有盘子移动到柱子C上，每次只能移动一个盘子，输出移动每一次过程。
//每次移动占一行，第一个数表示第几步移动，第二个数是移动的盘子的半径，然后是从哪个柱子移动到哪个柱子。
//样例
//2
// 1 1 A->B
// 2 2 A->C
// 3 1 B->C
//递归问题 大家都知道思路，终点是代码转换
// #include <iostream>
// using namespace std;

// void moveDisks(int n, char A, char C, char B, int &step) 
// {
//     if (n == 1) 
//     {
//         // 如果只有一个盘子，直接从 A 移动到 C
//         cout << step++ << " " << n << " " << A << "->" << C << endl;
//         return;
//     }

//     // 将 n-1 个盘子从 A 移动到 B，使用 C 作为辅助
//     moveDisks(n - 1, A, B, C, step);

//     // 将第 n 个盘子从 A 移动到 C
//     cout << step++ << " " << n << " " << A << "->" << C << endl;

//     // 将 n-1 个盘子从 B 移动到 C，使用 A 作为辅助
//     moveDisks(n - 1, B, C, A, step);
// }

// int main() 
// {
//     int n;
//     cin >> n;
//     int step = 1;
//     moveDisks(n, 'A', 'C', 'B', step);
//     return 0;
// }
#include <iostream>
using namespace std;
void movedisk()
{

}
int main()
{
    int n;//移动的圆盘个数
    cin>>n;
    int step=1;//记录移动的步数
    
}