#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int d[1000001];

    d[1] = 0;

    for(int k=2; k<n+1; k++) {
        if (k % 3 == 0 && k % 2 == 0) {
            d[k] = min({d[k/3]+1, d[k/2]+1, d[k-1]+1});    
        } else if (k % 3 == 0) {
            d[k] = min(d[k/3]+1, d[k-1]+1);
        } else if (k % 2 == 0) {
            d[k] = min(d[k/2]+1, d[k-1]+1);
        } else d[k] = d[k-1]+1;
    }

    cout << d[n];

}