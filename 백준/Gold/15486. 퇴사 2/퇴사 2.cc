#include <bits/stdc++.h>
using namespace std;

int last[1500005];
int price[1500005];
int dp[1500005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i=1;i<=N;i++) {
        cin >> last[i];
        cin >> price[i];
    }
    
    for (int i=1;i<=N+1;i++) {
        dp[i] = max(dp[i], dp[i-1]);
        dp[i+last[i]]=max(dp[i+last[i]], dp[i]+price[i]);
    }

    cout << dp[N+1];

}