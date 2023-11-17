#include <iostream>
#include <cmath>
using namespace std;

double kList[100100], thetaList[100100];

int main()
{
    int m, n, i;
    kList[0] = 1;
    cin >> n >> m;
    int type;
    double t;
    for (i = 1; i <= n; ++i)
    {
        cin >> type >> t;
        if (type == 1)
        {
            kList[i] = kList[i - 1] * t;
            thetaList[i] = thetaList[i - 1];
        }
        else
        {
            kList[i] = kList[i - 1];
            thetaList[i] = thetaList[i - 1] + t;
        }
    }
    int start, des;
    double x, y, newx, newy;
    double k, theta;
    for (i = 1; i <= m; ++i)
    {
        cin >> start >> des >> x >> y;
        k = kList[des] / kList[start - 1];
        theta = thetaList[des] - thetaList[start - 1];
        newx = k * (x * cos(theta) - y * sin(theta));
        newy = k * (x * sin(theta) + y * cos(theta));
        printf("%lf %lf\n", newx, newy);
    }
    return 0;
}