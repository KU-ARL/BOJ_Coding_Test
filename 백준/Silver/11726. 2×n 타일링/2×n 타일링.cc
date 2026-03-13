#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int sum[1005];

    sum[1] = 1;
    sum[2] = 2;

    for(int i=3;i<=N;i++) {
        sum[i] = (sum[i-1] + sum[i-2]) % 10007;
    }

    cout << sum[N];
}