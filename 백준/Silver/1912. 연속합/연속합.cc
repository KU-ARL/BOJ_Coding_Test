#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int list[N+1];

    for (int i=0; i<N; i++) {
        cin >> list[i];
    }


    int current_sum = list[0];
    int max_sum = list[0];

    for (int i = 1; i < N; i++) {
        current_sum = max(list[i], current_sum + list[i]);
        
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum;
}