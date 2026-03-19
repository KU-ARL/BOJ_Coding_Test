#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, N;
    cin >> K >> N;

    long long max_len=0;

    vector<long long> v;
    for(int i=0; i<K; i++) {
        long long n;
        cin >> n;
        max_len = max(n, max_len);
        v.push_back(n);
    }

    long long high = max_len;
    long long low = 1;
    

    
    long long ans = 0;

    while(low <= high) {

        long long mid = (high + low) / 2;

        long long cnt = 0;

        for(int i=0; i<v.size();i++) {
            cnt += v[i]/mid;
        }
        if(cnt < N) {
            high = mid - 1;
        }
        else {
            ans = mid;
            low = mid + 1;
        }
    }

    cout << ans;



}