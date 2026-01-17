#include <bits/stdc++.h>
using namespace std;


int sum[10000];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int num[N];
    for (int i=0; i<N; i++) cin >> num[i];
    

    sum[0] = num[0];
    if(N>1) sum[1] = num[0] + num[1];
    if(N>2) {
        for (int i=2; i<N; i++) {
            sum[i] = max({sum[i-1], sum[i-2]+num[i], sum[i-3]+num[i-1]+num[i]});
        }
    }

    cout << sum[N-1];

}