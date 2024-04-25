#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAXN 100010

struct Edge
{
    int to, nxt;
} edges[MAXN << 1];
int n, d, cnt, head[MAXN];

void addEdge(int u, int v)
{
    ++cnt;
    edges[cnt].to = v;
    edges[cnt].nxt = head[u];
    head[u] = cnt;
}

bool visit[MAXN];        // 是否已经找到最短路
queue<pair<int, int>> q; // 队列

int BFS(int root)
{
    int ret = 0, depth = 0;
    q.push(make_pair(root, depth));
    while (q.size())
    {
        pair<int, int> top_pair = q.front();
        q.pop();
        root = top_pair.first;
        depth = top_pair.second;
        visit[root] = true;
        if (depth && depth <= d)
            ret++;
        for (int i = head[root]; i; i = edges[i].nxt)
        {
            int to = edges[i].to;
            if (!visit[to] && depth < d)
            {
                q.push(make_pair(to, depth + 1));
            }
        }
    }
    return ret;
}

int main()
{
    cin >> n >> d;
    int u, v, i;
    for (i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    cout << BFS(1) << endl;
    return 0;
}
