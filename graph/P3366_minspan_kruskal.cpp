#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXE 200200
#define MAXN 5050

struct Edge
{
    int u;
    int w;
    int v;
} edges[MAXE << 1];
int cnt = 0, N, M, ret;
int num_edges = 0; // 加入最小树种的节点数

void addEdge(int u, int v, int w)
{
    edges[cnt].u = u;
    edges[cnt].w = w;
    edges[cnt].v = v;
    ++cnt;
}

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

// 并查集
int Parents[MAXN]; // 每个点的祖宗
int find(int root)
{
    if (Parents[root] == root)
        return root;
    Parents[root] = find(Parents[root]);
    return Parents[root];
}

void merge(int x, int y)
{
    Parents[find(x)] = find(y);
}

bool cmpParents(int x, int y)
{
    return find(x) == find(y);
}

void kruskal()
{
    /*
    所有边进行排序
    得到最小边，看当前最小边的两个端点是否构成自环，不构成则将其合并，该边权加入结果
    */
    sort(edges, edges + M, cmp);
    int i;
    num_edges = 0;
    for (i = 0; i < M && num_edges < N - 1; ++i)
    {
        Edge e_cur = edges[i];
        if (cmpParents(e_cur.u, e_cur.v))
            continue;
        ret += e_cur.w;
        num_edges += 1;
        merge(e_cur.u, e_cur.v);
    }
    if (num_edges < N - 1)
        ret = -1;
}

int main()
{
    cin >> N >> M;
    int i, u, v, w;
    for (i = 1; i <= N; ++i)
        Parents[i] = i;
    for (i = 0; i < M; ++i)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    kruskal();
    if (ret > 0)
        cout << ret << endl;
    else
        cout << "orz" << endl;
    return 0;
}
