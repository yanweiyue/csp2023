#include <iostream>
#include <vector>
using namespace std;
#define N 100050

vector<int> data;
vector<int> primes; // 素数列表
bool not_prime[N];  // 为0是素数，为1不是素数

void EulerPrime(int n)
{
    /*线性素数筛
    遍历x
    如果是素数则加入素数列表
    再和素数列表中所有元素相乘
    如果当前素数p是x的因数，那么不再相乘*/
    for (int i = 2; i <= n; ++i)
    {
        if (!not_prime[i]) // 是素数
            primes.emplace_back(i);
        for (int p : primes)
        {
            if (p * i > n)
            { // 超出限制
                break;
            }
            not_prime[p * i] = true;
            if (i % p == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    not_prime[1] = true;
    int n, temp, i;
    cin >> n;
    EulerPrime(100000);
    for (i = 0; i < n; ++i)
    {
        cin >> temp;
        if (!not_prime[temp]) // 素数
        {
            cout << temp << " ";
        }
    }
    return 0;
}