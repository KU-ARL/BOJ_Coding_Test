#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long num[105];
    num[1]=1;
    num[2]=1;
    num[3]=1;
    num[4]=2;
    num[5]=2;

    for(int i=6;i<101;i++) {
        num[i] = num[i-1] + num[i-5];
    }

    while(N--) {
        int n;
        cin >> n;

        cout << num[n] <<'\n';
    }
}