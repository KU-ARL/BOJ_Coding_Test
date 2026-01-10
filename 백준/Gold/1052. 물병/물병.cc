#include <bits/stdc++.h>
using namespace std;

int N, K;
int addition;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;


    for(int i=0; i<K; i++) {
        int pow2 = 1;
        while(N > pow2) {
            pow2 *= 2;
        }
        N = N-pow2/2;
        addition = pow2/2;
        // cout << N << '\n';
        // cout << addition << '\n';
    }
    int result = addition - N;

    if (result == -1) cout << 0;
    else if (result<0) cout << -1;
    else cout << result;



}