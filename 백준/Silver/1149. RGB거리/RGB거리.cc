#include <bits/stdc++.h>
using namespace std;

int cost[1005][3];
int R[1005];
int G[1005];
int B[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i=1; i<=N; i++) {
            cin >> R[i] >> G[i] >> B[i];
    }

    cost[1][0] = R[1];
    cost[1][1] = G[1];
    cost[1][2] = B[1];

    for (int i=2; i<=N; i++) {
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + R[i];
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + G[i];
        cost[i][2] = min(cost[i-1][1], cost[i-1][0]) + B[i];
    }

    cout << min({cost[N][0], cost[N][1], cost[N][2]});
}