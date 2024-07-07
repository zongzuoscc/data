// 给你一个有向图的所有顶点有序对，顶点用1~n编号，每个有序对描述有向边，请编程求解从1到任意一个顶端i的最短路径长度。
// 第一行是n和m,分别表示顶点数（n<100）和有向边数(m<100)。
// 从第二行开始n行，对应三个数，前两个表示顶点有序对，第三个数表示边的权。
// 最后一行i，表示要求解从1到顶点i的最短路径长度。
// 从1到顶点i的最短路径长度。
//这个和acwing的题基本是一样的，只不过acwing是只输出到最后一个结点的距离  本质上都是朴素的dijkstra算法
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=510;
int n,m;
int g[N][N];
int dist[N];//dijkstra算法里面的距离 表示的是从一号点走到每个点的距离是多少  当前的最短距离是多少
bool st[N];//表示每个点的最短路是不是已经确定了
int dijkstra(int target)
{
    memset(dist,0x3f,sizeof dist);//初始化距离为正无穷
    dist[1]=0;//将一号点初始化为0；
    for(int i=0;i<n-1;i++)//迭代n次  
    {
        //每次第一步先找最小值
        //找到当前没有确定最短路长度的点当中 距离最小的那一个
        int t=-1;//表示还没有确定
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[j]<dist[t]))//如果说当前这个点还没有确定最短路并且t=-1或当前这个t不是最短的的话 
            {
                t=j;//那么就把t赋值成j
            }
        }
        st[t]=true;//把t加到集合里面去

        //拿t来更新其他点的距离
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);//从用1到t的距离+t到j的距离 来更新从1到j这条边
        }

    }
    if(dist[target]==0x3f3f3f3f)//如果从1到n是正无穷 说明是不连通的
    {
        return -1;
    }
    else
    {
        return dist[target];
    }
}
int main()
{
    cin>>n>>m;//读入点数和边数

    memset(g,0x3f,sizeof g);//和上面一长串代码原理相同
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);//因为可能有多条边 所有这一步是保留长度最短的边
    }
    int target;
    cin>>target;
    int t=dijkstra(target);
    cout<<t<<endl;
    return 0;
}