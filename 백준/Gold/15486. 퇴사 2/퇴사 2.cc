#include <bits/stdc++.h>
using namespace std;

int last[1500005];
int price[1500005];

int sum[1500005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++) {
        cin >> last[i];
        cin >> price[i];
    }

    for(int i=1;i<=N+1;i++) {
        sum[i] = max(sum[i-1], sum[i]);
        if(i+last[i] <= N+1) sum[i+last[i]] = max(sum[i+last[i]], sum[i]+price[i]);
    }

    cout << sum[N+1];
}