#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long M;
    cin >> N >> M;

    long long max_len;
    vector<long long> v;

    for(int i=0; i<N; i++) {
        long long input;
        cin >> input;
        v.push_back(input);
        max_len = max(max_len, input);
    }
    
    long long low=0;
    long long high=max_len;
    long long ans=0;

    while(low<=high) {
        long long mid=(low + high) / 2;

        long long sum=0;

        for (long long len: v) {
            if(len-mid >=0) sum += len-mid;
        }

        if(sum>=M) {
            ans = mid;
            low = mid+1;
        } else high = mid - 1;
    }

    cout << ans;

}