// 链式前向星存树，求树的重心
#include <iostream>
#include <vector>
#define MAXN 50020
using namespace std;

// 链式前向星存边集，和点起点集(对应边集中的index)
struct Edge
{
    int to, next;   // 每条边的起点由head的index确定，因此只需存每条边的终点->to，相同起点的下一条边在边集中的index->next
} edges[MAXN << 1]; // 边集
int head[MAXN];     // 每个点作为起点的第一条边在边集中的index,无边为0
int cnt = 0;        // 当前边的个数
int res[MAXN];
int subSize[MAXN]; // 以每个节点为根的子树节点数
int visit[MAXN];   // dfs使用保存是否访问
int depth[MAXN];   // 每个节点的深度
int n;             // 题目参数，节点数
void addEdge(int u, int v)
{
    ++cnt;
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

// dfs得到每个节点的深度和每个节点子树的大小
void dfs1(int root, int d)
{
    visit[root] = true;
    depth[root] = d;
    subSize[root] = 1;
    for (int i = head[root]; i; i = edges[i].next)
    {
        int to = edges[i].to; // 目标节点编号
        if (visit[to])        // 遍历过这个点了
            continue;
        dfs1(to, d + 1);
        subSize[root] += subSize[to];
    }
}

void dfs2(int root, int father)
{
    res[root] = res[father] - 2 * subSize[root] + n;
    for (int i = head[root]; i; i = edges[i].next)
    {
        int to = edges[i].to;
        if (to == father)
            continue;
        dfs2(to, root);
    }
}

int main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    // 默认以1为根，首先遍历树得到初始值和subSize
    dfs1(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        res[1] += depth[i];
    }
    int minI = 1, minVal = res[1];
    for (int i = head[1]; i; i = edges[i].next)
    {
        int to = edges[i].to;
        dfs2(to, 1);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (res[i] < minVal)
        {
            minI = i;
            minVal = res[i];
        }
    }
    cout << minI << " " << minVal << endl;
    return 0;
}