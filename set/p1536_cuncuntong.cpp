#include <iostream>
#include <set>
using namespace std;

int m, n, x, y;
int father[1010];

int find(int a)
{
    if (father[a] == a)
    {
        return a;
    }
    return father[a] = find(father[a]);
}

void merge(int a, int b)
{
    father[find(a)] = find(b);
}

int main()
{
    while (true)
    {
        set<int> ancestors;
        cin >> n;
        if (!n)
            break;
        cin >> m;
        for (int i = 1; i <= n; ++i)
        {
            father[i] = i;
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> x >> y;
            merge(x, y);
        }
        for (int i = 1; i <= n; ++i)
        {
            ancestors.insert(find(i));
        }
        cout << ancestors.size() - 1 << endl;
        ancestors.clear();
    }
    return 0;
}