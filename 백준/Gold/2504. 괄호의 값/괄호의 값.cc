#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string inp;
    cin >> inp;

    stack<char> st;

    long long ans=0;
    long long temp=1;

    for(int i=0; i<inp.size();i++) {
        if(inp[i]=='(') {
            st.push(inp[i]);
            temp*=2;
        } else if(inp[i]=='[') {
            st.push(inp[i]);
            temp*=3;
        } else if(inp[i]==')') {
            if(st.empty() || st.top()!='(') {
                cout << 0 << '\n';
                return 0;
            }
            else{
                if(inp[i-1] == '(') {
                    ans += temp;
                    temp = temp / 2;
                    st.pop();
                } else {
                    st.pop();
                    temp = temp / 2;
                }
            }
        } else if(inp[i]==']') {
            if(st.empty() || st.top()!='[') {
                cout << 0 << '\n';
                return 0;
            }
            else {
                if(inp[i-1] == '[') {
                    ans += temp;
                    st.pop();
                    temp = temp / 3;
                } else {
                    st.pop();
                    temp = temp / 3;
                }
            }
        }
    }

    if(!st.empty()) cout << 0;
    else cout << ans;

}