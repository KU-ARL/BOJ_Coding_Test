
#include <bits/stdc++.h>
using namespace std;

int num[1005];
int sum[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i=1;i<=N;i++) {
        cin >> num[i];
        sum[i] = num[i];
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<i;j++) {
            if(num[j] < num[i]) {
                sum[i] = max(sum[i], sum[j]+num[i]);
            }
        }
    }


    int result = 0;
    for (int i=1;i<=N;i++) result = max(result, sum[i]);
    cout << result;


}