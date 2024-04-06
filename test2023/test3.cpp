#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

long long int MODE = 1e9 + 7;

struct item
{
    /* the item of the formula */
    long long int coef; // coefficient of the item
    map<int, int> mp;   // map the item index to the power
    item(long long int ceo, map<int, int> m) : coef(ceo), mp(m){};
};

struct formula
{
    vector<item> vec; // all the item concatenate with plus
    formula(vector<item> v) : vec(v){};
};

formula FormulaAdd(const formula &A, const formula &B)
{
    /*两个方程相加*/
    // 直接将这个B中的项添加到A中
    formula C(A.vec);
    C.vec.insert(A.vec.end(), B.vec.begin(), B.vec.end());
    return C;
}

formula FormulaSub(const formula &A, const formula &B)
{
    /*A-B*/
    formula C(A.vec);
    int i;
    for (i = 0; i < B.vec.size(); ++i)
    {
        item item_B(-B.vec[i].coef, B.vec[i].mp);
        C.vec.emplace_back(item_B);
    }
    return C;
}

formula FormulaMul(const formula &A, const formula &B)
{
    ;
}

/*convert str to longlong int*/
long long int Str2LL(const string &str)
{
    long long int t;
    istringstream ss(str);
    ss >> t;
    return t;
}

stack<formula> st;

int main()
{
    int n, m;
    cin >> n >> m;
    string str, t;
    getchar();
    while (getline(cin, str))
    {
        stringstream ssStr(str);
        if (t == "+" || t == "-" || t == "*")
        {
            formula A = st.top();
            st.pop();
            formula B = st.top();
            st.pop();
            if (t == "+")
                st.push(FormulaAdd(B, A)); // B+A
            if (t == "-")
                st.push(FormulaSub(B, A)); // B-A
            if (t == "*")
                st.push(FormulaMul(B, A)); // B*A
        }
        else
        {
            map<int, int> m;
            vector<item> v; // 对于单个变量也将其转化为方程，因此需要这个vec
            if (t[0] == 'x')
            { // 属于自变量
                m[Str2LL(t.substr(1, t.length() - 1))] = 1;
                v.push_back(item(1, m));
            }
            else // 属于常数
                v.push_back(item(Str2LL(t), m));
            st.push(v);
        }
    }

    return 0;
}