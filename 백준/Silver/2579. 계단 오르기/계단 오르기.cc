#include <bits/stdc++.h>
using namespace std;

int s[305];
int d[305];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int sum = 0;

    for(int i=1;i<=N;i++) {
        cin >> s[i];
        sum += s[i];
    }

    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];

    for(int i=4;i<=N;i++) {
        d[i] = min(d[i-3], d[i-2]) + s[i];
    }
    
    cout << sum - min(d[N-1], d[N-2]);
}