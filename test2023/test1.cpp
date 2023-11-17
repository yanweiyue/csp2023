#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    long long int dx=0, dy=0;
    int nowDx, nowDy;
    for (int i = 0; i < n;++i)
    {
        cin >> nowDx >> nowDy;
        dx += nowDx;
        dy += nowDy;
    }
    int x, y;
    for (int i = 0; i < m;++i)
    {
        cin >> x >> y;
        cout << x + dx << " " << y + dy << endl;
    }
    return 0;
}