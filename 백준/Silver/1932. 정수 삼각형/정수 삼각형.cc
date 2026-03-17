#include <bits/stdc++.h>
using namespace std;

int tri[505][505];
int dp[505][505];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            cin >> tri[i][j];
        }
    }

    dp[1][1] = tri[1][1];
    dp[2][1] = tri[2][1] + dp[1][1];
    dp[2][2] = tri[2][2] + dp[1][1];

    for (int i=3; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
        }
    }

    int result = 0;
    for (int i=1; i<=N; i++) {
        result = max(result, dp[N][i]);
    }

    cout << result;
}