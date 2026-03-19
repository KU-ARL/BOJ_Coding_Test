#include <bits/stdc++.h>
using namespace std;

int board[100005];
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    if(N==K) {
        cout << 0;
        return 0;
    }

    queue<int> Q;
    board[N] = 1;
    Q.push(N);

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        int nx[3] = {cur+1, cur-1, cur*2};

        for(int i=0; i<3; i++) {

            if(nx[i]<0 || nx[i]>=100005) continue;
            if(board[nx[i]]!=0) continue;

            Q.push(nx[i]);
            board[nx[i]] = board[cur]+1;

            if(nx[i]==K) {
                cout << board[nx[i]]-1;
                return 0;
            }
        }
    }
}