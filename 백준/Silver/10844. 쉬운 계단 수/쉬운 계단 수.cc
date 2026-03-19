#include <bits/stdc++.h>
using namespace std;

long long num[105][10];
const int mod = 1000000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    num[1][0] = 0;
    for(int i=1;i<=9;i++) num[1][i] = 1;

    for(int i=2;i<=N;i++) {
        for(int j=0;j<=9;j++) {
            if(j!=0) num[i][j] += num[i-1][j-1] % mod;
            if(j!=9) num[i][j] += num[i-1][j+1] % mod;
        }
    }

    long long ans = 0;
    for(int i=0;i<=9;i++) ans += num[N][i] % mod;

    cout << ans % mod;
}