// 有一项大的工程，工程中有许多前后依赖的子任务，每个子任务都规划了完成需要的天数，
// 假设给出用字母表示的事件结点，整个工程的开始事件用A表示，工程结束事件用Z表示，
// 用事件结点有序对表示一个子任务的开始和结束，并给出每个子任务完成需要的天数。请编程求解完成这个工程的最短天数。
// 第一行是事件结点的个数N（N<26）和子任务数M。（其实就是边数）
// 从第二行开始M行，每行是子任务的开始事件和结束事件以及完成该子任务所需天数。
// 完成该工程所需的最少天数。
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 26; // 最多26个节点（A-Z）

// 定义边结构体，包含目标节点和边的权重（任务所需时间）
struct Edge {
    int destination;
    int weight;
};

// 邻接表存储图，graph[i] 表示节点 i 的所有出边
vector<Edge> graph[MAXN]; // graph是一个数组，每个元素是一个向量，表示与节点 i 相关的所有边
int inDegree[MAXN];       // 入度表，用于存储每个节点的入度
int earliestStartTime[MAXN]; // 最早开始时间

int calculateShortestTime(int n) {
    memset(inDegree, 0, sizeof(inDegree)); // 将入度初始化为0
    memset(earliestStartTime, -1, sizeof(earliestStartTime)); // 将最早开始时间初始化为-1

    // 统计每个节点的入度
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) { // 遍历节点 i 的所有出边
            int nextNode = graph[i][j].destination;
            inDegree[nextNode]++; // 目标节点的入度加1
        }
    }

    // 初始化起点 A 的最早开始时间为 0
    earliestStartTime['A' - 'A'] = 0;

    // 使用拓扑排序计算每个节点的最早开始时间
    queue<int> q;
    q.push('A' - 'A'); // 起点 A 入队

    while (!q.empty()) {
        int currentNode = q.front(); // 取队首元素
        q.pop();

        for (int j = 0; j < graph[currentNode].size(); ++j) { // 遍历当前节点的所有出边
            int nextNode = graph[currentNode][j].destination;
            int nextStartTime = earliestStartTime[currentNode] + graph[currentNode][j].weight; // 计算目标节点的最早开始时间
            earliestStartTime[nextNode] = max(earliestStartTime[nextNode], nextStartTime); // 更新目标节点的最早开始时间

            if (--inDegree[nextNode] == 0) { // 如果目标节点的入度减为0，则入队
                q.push(nextNode);
            }
        }
    }

    // 返回工程的最短天数，即 Z 的最早开始时间
    return earliestStartTime['Z' - 'A'];
}

int main() {
    int N, M;
    cin >> N >> M;

    // 读取子任务信息
    for (int i = 0; i < M; ++i) {
        char startNode, endNode;
        int weight;
        cin >> startNode >> endNode >> weight;
        graph[startNode - 'A'].push_back({ endNode - 'A', weight }); // 将边加入邻接表
    }

    int shortestTime = calculateShortestTime(N); // 计算最短时间
    cout << shortestTime << endl; // 输出结果

    return 0;
}
