#include <bits/stdc++.h>
using namespace std;

int dp[42];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--) {
        string input;
        cin >> input;

        int cnt;
        cin >> cnt;

        string arr;
        cin >> arr;

        deque<int> dq;
        string temp="";

        for(int i=0; i<arr.length();i++) {
            if(isdigit(arr[i])) temp+=arr[i];
            else {
                if (!temp.empty()){
                    dq.push_back(stoi(temp));
                    temp="";
                }
            }
        }

        bool reverse = 0;
        bool error = 0;

        for(int i=0; i<input.length(); i++) {
            if (input[i]=='R') {
                reverse = !reverse;
            } else {
                if(dq.size()==0) {
                    error=1;
                    continue;
                } else {
                    if(!reverse) {
                        // cout << dq.front();
                        dq.pop_front();
                    }
                    else {
                        // cout << dq.back();
                        dq.pop_back();
                    }
                }
            }
        }

        if(!error) {
            cout << '[';
            if (reverse) {
                for (int i = (int)dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if (i > 0) cout << ",";
                }
            } else {
                for (int i = 0; i < (int)dq.size(); i++) {
                    cout << dq[i];
                    if (i < (int)dq.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        } else {
            cout << "error" << '\n'; 
        }

    }

}