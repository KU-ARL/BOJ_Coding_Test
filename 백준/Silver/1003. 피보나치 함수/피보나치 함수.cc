#include <bits/stdc++.h>
using namespace std;

int dp[42];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = 1;
    dp[1] = 0;

    for(int i=2; i<42; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int N;
    cin >> N;

    while(N--) {
        int p;
        cin >> p;

        cout << dp[p] << ' ' << dp[p+1] << '\n';
    }

}