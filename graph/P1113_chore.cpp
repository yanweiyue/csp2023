#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> G[10500];
int ans[10500], indegree[10500], t[10500];
queue<int> q;
int final_ans;

int main()
{
    int n, no, len, pre;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> no >> len;
        t[no] = len;
        while (true)
        {
            cin >> pre;
            if (pre == 0)
                break;
            indegree[no]++;
            G[pre].emplace_back(no);
        }
    }
    q.push(1);
    ans[1] = t[1];
    final_ans = t[1];
    while (q.size())
    {
        int start_no = q.front();
        q.pop();
        for (int i = 0; i < G[start_no].size(); ++i)
        {
            int end_no = G[start_no][i];
            --indegree[end_no];
            ans[end_no] = max(ans[start_no] + t[end_no], ans[end_no]);
            if (indegree[end_no] == 0)
            {
                final_ans = max(final_ans, ans[end_no]);
                q.push(end_no);
            }
        }
    }
    cout << final_ans;
    return 0;
}