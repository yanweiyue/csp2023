#include <iostream>
using namespace std;
#define MAXN 100100
struct people
{
    int left;
    int right;
} pList[MAXN];
int N, M;

int main()
{
    cin >> N;
    pList[0].left = -1;
    pList[0].right = 1;
    pList[1].left = 0;
    pList[1].right = N + 1;
    pList[N + 1].left = 1;
    pList[N + 1].right = -1;
    int i, no, dir, l_no, r_no;
    for (i = 2; i <= N; ++i)
    {
        cin >> no >> dir;
        if (dir == 0)
        { // 插入该学生左边
            l_no = pList[no].left;
            pList[l_no].right = i;
            pList[i].left = l_no;
            pList[i].right = no;
            pList[no].left = i;
        }
        else
        { // 插入该学生的右边
            r_no = pList[no].right;
            pList[r_no].left = i;
            pList[i].left = no;
            pList[i].right = r_no;
            pList[no].right = i;
        }
    }
    cin >> M;
    for (i = 1; i <= M; ++i)
    {
        cin >> no;
        l_no = pList[no].left;
        r_no = pList[no].right;
        if (pList[l_no].right != no || pList[r_no].left != no)
            continue;
        pList[l_no].right = r_no;
        pList[r_no].left = l_no;
    }
    no = pList[0].right;
    while (no != -1 && no <= N)
    {
        /* code */
        cout << no << " ";
        no = pList[no].right;
    }
    return 0;
}