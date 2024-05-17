#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXE 200200
#define MAXN 5050

struct Edge
{
    int to;
    int w;
    int next;
} edges[MAXE << 1];
int head[MAXN], dis[MAXN]; // 每个节点的首边在边数组中的序号,已选点到每个点的最短距离
int cnt = 0, N, M;
bool visited[MAXN]; // 是否加入最小树中

void addEdge(int u, int v, int w)
{
    ++cnt;
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

int prim()
{
    /*将所有点分为在组内和不在组内
    找不在组内的所有点到组内点的最短边
    当最短边被找出，目标点进入组内，并查找其入组是否能缩短其他点入组的距离
    待查边集：优先队列维护
    */
    int sum = 0, num_node = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
    while (!q.empty() && num_node < N)
    {
        /* code */
        int d = q.top().first, v = q.top().second;
        q.pop();
        if (visited[v])
            continue;
        visited[v] = true;
        num_node += 1;
        sum += d;
        dis[v] = 0;
        for (int idx = head[v]; idx != -1; idx = edges[idx].next)
        {
            int vv = edges[idx].to; // 所指向的节点
            if (edges[idx].w < dis[vv])
            {
                dis[vv] = edges[idx].w;
                q.emplace(make_pair(dis[vv], vv));
            }
        }
    }
    if (num_node == N)
        return sum;
    return -1;
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(dis, 127, sizeof(dis));
    cin >> N >> M;
    int i, u, v, w;
    for (i = 0; i < M; ++i)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int ret = prim();
    if (ret < 0)
        cout << "orz" << endl;
    else
        cout << ret << endl;
    return 0;
}
