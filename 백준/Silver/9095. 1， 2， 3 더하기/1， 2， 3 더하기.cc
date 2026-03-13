#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int d[12];

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    while(N--) {
        int n;
        cin >> n;

        for(int i=4; i<=n; i++) {
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }

        cout << d[n] << '\n';
    }
}