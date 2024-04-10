// 并查集模板题
#include <iostream>
using namespace std;

int n, m, p, x, y;
int father[5050];

int find(int a)
{
    if (father[a] == a)
        return a;
    return father[a] = find(father[a]);
}

void merge(int a, int b)
{
    father[find(a)] = find(b);
}

int main()
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
    {
        father[i] = i;
    }
    /*进行一系列合并*/
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0; i < p; ++i)
    {
        cin >> x >> y;
        if (find(x) == find(y))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}