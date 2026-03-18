#include <bits/stdc++.h>
using namespace std;

int sum[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    sum[1] = 1;
    sum[2] = 3;

    for (int i=3;i<=N;i++) {
        sum[i] = (sum[i-2] * 2 + sum[i-1]) % 10007;
    }

    cout << sum[N];
}