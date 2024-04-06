#include <iostream>
using namespace std;

struct country
{
    int no;
    int w;
    country(int n, int weight)
    {
        no = n;
        w = weight;
    }
    country()
    {
        no = -1;
        w = -1;
    }
};

country data[300];
int dict2[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

int main()
{
    int n, w;
    cin >> n;
    int country_num = dict2[n];
    for (int i = 0; i < country_num; ++i)
    {
        cin >> w;
        data[i + country_num] = country(i + 1, w);
    }
    for (int i = country_num - 1; i >= 2; --i)
    {
        int left_parent = i * 2;
        int right_parent = i * 2 + 1;
        if (data[left_parent].w > data[right_parent].w)
        {
            data[i] = data[left_parent];
        }
        else
        {
            data[i] = data[right_parent];
        }
    }
    if (data[2].w > data[3].w)
    {
        cout << data[3].no;
    }
    else
    {
        cout << data[2].no;
    }
    return 0;
}