#include <bits/stdc++.h>
using namespace std;

long long num[10];
long long tem[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    num[0] = 0;
    for (int i=1;i<=9;i++) num[i]=1;

    int N;
    cin >> N;

    for (int i=2;i<=N;i++) {
        tem[0] = num[1] % 1000000000;
        tem[9] = num[8] % 1000000000;

        for (int j=1;j<9;j++) {
            tem[j] = (num[j-1]+num[j+1]) % 1000000000;
        }

        for (int j=0;j<=9;j++) {
            num[j] = tem[j];
        }   

    }

    long long result = 0;
    for (int i=0;i<=9;i++) {
        result = (result+num[i]) % 1000000000;
    }
    cout << result;
}