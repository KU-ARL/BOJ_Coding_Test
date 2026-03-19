#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;

    while(N--) {
        int input;
        cin >> input;
        if(input == 0) {
            if(pq.size()==0) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n'; 
                pq.pop();
            }
        } else pq.push(input);
    }

}