#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> st;
int main()
{
    string str;
    int a, b, ret, num = 0;
    cin >> str;
    for(char c:str){
        if(c=='-'||c=='+'||c=='*'||c=='/'){
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if(c=='-')
                ret = a - b;
            else if(c=='+')
                ret = a + b;
            else if(c=='*')
                ret = a * b;
            else if(c=='/')
                ret = a / b;
            st.push(ret);
        }
        else if(c=='@'){
            ret = st.top();
            cout << ret;
            break;
        }
        else if(c=='.'){
            st.push(num);
            num = 0;
        }
        else{
            num = (c - '0') + num * 10;
        }
    }
    return 0;
}