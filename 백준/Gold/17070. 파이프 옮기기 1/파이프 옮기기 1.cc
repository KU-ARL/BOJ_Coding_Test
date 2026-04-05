#include <bits/stdc++.h>
using namespace std;

int board[17][17];
int vis[17][17][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> board[i][j];
        }
    }

    vis[1][2][1] = 1;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(board[i][j] == 1) continue;
            
            if(j-1>0 && board[i][j-1] == 0) vis[i][j][1] += vis[i][j-1][1] + vis[i][j-1][3];

            if(i-1>0 && board[i-1][j] == 0) vis[i][j][2] += vis[i-1][j][2] + vis[i-1][j][3];

            if(j-1>0 && i-1>0 && board[i-1][j]+board[i][j-1] == 0) vis[i][j][3] += vis[i-1][j-1][1] + vis[i-1][j-1][2] + vis[i-1][j-1][3];

        }
    }

    cout << vis[N][N][1] + vis[N][N][2] + vis[N][N][3];
}