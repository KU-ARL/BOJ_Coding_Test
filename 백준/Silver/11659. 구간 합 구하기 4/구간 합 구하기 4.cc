#include <bits/stdc++.h>
using namespace std;

int num[100005];
int sum[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    cin >> num[1];
    sum[1] = num[1];

    for (int i=2; i<=m; i++) {
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
    }

    
    while(n--) {
        int a, b;
        cin >> a >> b;

        cout << sum[b] - sum[a-1] <<'\n';
    }
}