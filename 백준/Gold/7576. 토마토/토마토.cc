#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[1005][1005];
int vis[1005][1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    queue<pair<int, int>> Q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j]==1) {
                Q.push({i, j});
                vis[i][j] = 1;
            } else if(board[i][j]==-1) {
                vis[i][j]=-1;
            }
        }
    }

    // cout << '\n';
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << board[i][j];
    //     }
    //     cout << '\n';

    // }

    // cout << '\n';
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << vis[i][j];
    //     }
    //     cout << '\n';

    // }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0 || vis[nx][ny] != 0) continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int result = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(vis[i][j]==0) {
                // cout << i << ',' << j << '\n';
                cout << -1;
                return 0;
            }

            result = max(result, vis[i][j]);
        }
    }

    cout << result - 1;
}