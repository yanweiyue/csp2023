#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

vector<int> G[100500];
bool visited[100500];

void dfs(int root)
{
    cout << root << " ";
    visited[root] = true;
    for (int i = 0; i < G[root].size(); ++i)
    {
        int next = G[root][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

void bfs(int root)
{
    visited[root] = true;
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        root = q.front();
        cout << root << " ";
        q.pop();
        for (int i = 0; i < G[root].size(); ++i)
        {
            int next = G[root][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    int m, n, i, x, y;
    cin >> n >> m;
    for (i = 0; i < m; ++i)
    {
        cin >> x >> y;
        G[x].emplace_back(y);
    }
    for (i = 1; i <= n; ++i)
    {
        sort(G[i].begin(), G[i].end());
    }
    dfs(1);
    cout << endl;
    memset(visited, '\0', sizeof(bool) * 100500);
    bfs(1);
    return 0;
}