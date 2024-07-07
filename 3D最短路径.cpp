// 一个迷宫地图中，多个房间由单向通道相连，房间号从1到N依次编号。你能编程求解任意房间间的最短路径长度吗？
// 第一行是迷宫中的房间数N和单项通道数M（0<N,M<100），接下来M行，每行三个数x,y,z，表示一个通道是从x到y,且通道长度是z(z<1000）。
// 最后一行是start和end，分别是起点房间号和终点房间号
// 输出起点房间号和终点房间号间的最短路径长度。如果没有通路，输出STOP。
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <queue>
// using namespace std;
// const int INF = 0x3f3f3f3f; 
// const int MAXN = 100;
// vector<pair<int, int>> adj[MAXN]; // 邻接表表示图，adj[u]存储的是与u相邻的(v, w)对，v是相邻的节点，w是边权

// int dist[MAXN]; // dist数组存储起点到各点的最短距离
// bool visited[MAXN]; // visited数组标记节点是否已被访问
// void dijkstra(int start, int n) {
//     // 使用优先队列来实现Dijkstra算法，优先队列中存储(pair<int, int>)，第一个元素是距离，第二个元素是节点
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//小根堆
    
//     // 初始化dist数组和visited数组  
//     memset(dist,0x3f,sizeof dist);
//     memset(visited,false,sizeof visited);
//     // 起点的距离为0
//     dist[start] = 0;
//     pq.push({0, start}); // 将起点加入优先队列
//     while (!pq.empty())//非空 
//     {
//         int u = pq.top().second; // 取出队列中距离最小的节点，堆顶元素
//         pq.pop();
//         if (visited[u]) continue; // 如果该节点已访问，则跳过
//         visited[u] = true; // 标记该节点为已访问
//         // 遍历与节点u相邻的所有节点
//         for (int i = 0; i < adj[u].size(); i++) {
//             int v = adj[u][i].first;  // 相邻的节点
//             int weight = adj[u][i].second;  // 边的权重
            
//             // 如果通过u到v的路径比已知的最短路径更短，则更新最短路径
//             if (dist[u] + weight < dist[v]) {
//                 dist[v] = dist[u] + weight;
//                 pq.push({dist[v], v}); // 将更新后的节点v加入优先队列
//             }
//         }
//     }
// }

// int main() {
//     int n, m;
//     cin >> n >> m; // 输入节点数和边数
//     // 输入所有边的信息，并构建邻接表
//     for (int i = 0; i < m; i++) 
//     {
//         int x, y, z;
//         cin >> x >> y >> z;
//         adj[x].push_back({y, z}); // 添加边(x, y)到邻接表，权重为z
//     }
//     int start, end;
//     cin >> start >> end; // 输入起点和终点
//     dijkstra(start, n); // 运行Dijkstra算法计算最短路径
//     // 输出结果
//     if (dist[end] == INF) 
//     { // 如果终点不可达，则输出STOP
//         cout << "STOP" << endl;
//     } 
//     else 
//     { // 否则输出最短路径长度
//         cout << dist[end] << endl;
//     }
//     return 0;
// }


//由于上面的dijkstra算法太难记住代码，并且经过测试floyd算法也能成功ac，那么下面是更好记忆的floyd算法
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=210;
const int INF=1e9;
int n,m;
int d[N][N];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                d[i][j]=min(d[i][j],d[k][j]+d[i][k]);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                d[i][j]=0;
            }
            else
            {
                d[i][j]=INF;
            }
        }
    }
    while(m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        d[a][b]=min(d[a][b],w);
    }
    floyd();
    int start,end;
    cin>>start>>end;
    if(d[start][end]>INF/2)
    {
        cout<<"STOP"<<endl;
    }
    else
    {        
        cout<<d[start][end]<<endl; 
    }
    return 0;
}