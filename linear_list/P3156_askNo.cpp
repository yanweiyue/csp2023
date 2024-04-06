#include <iostream>
#include <map>

using namespace std;
map<pair<int, int>, int> data;

int main()
{
    int n, q;
    cin >> n >> q;
    int type, desk_no, block_no, item_no;
    for (int i = 0; i < q; ++i)
    {
        cin >> type >> desk_no >> block_no;
        if (type == 1)
        {
            cin >> item_no;
            data[{desk_no, block_no}] = item_no;
        }
        else
        {
            cout << data[{desk_no, block_no}] << endl;
        }
    }
    return 0;
}