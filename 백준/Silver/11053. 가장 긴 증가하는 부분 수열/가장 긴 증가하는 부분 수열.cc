#include <bits/stdc++.h>
using namespace std;

int num[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt[1005];
    fill(cnt, cnt+1005, 1);
    
    for(int i=1; i<=N; i++) {
        cin >> num[i];
    }

    cnt[1] = 1;
    for( int i=2; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            if(num[j] < num[i]) {
                cnt[i] = max(cnt[j]+1, cnt[i]);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=N;i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans;
}