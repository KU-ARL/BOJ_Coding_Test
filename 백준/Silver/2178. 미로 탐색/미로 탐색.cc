#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[105][105];
int vis[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string input;
        cin >> input;

        for(int j=0; j<input.size();j++) {
            board[i][j] = input[j] - '0';
        }
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vis[0][0] = 1;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i=0;i<4;i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx <0 || nx >= n || ny <0 || ny >=m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;

            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y]+1;
        }
    }

    cout << vis[n-1][m-1];

}