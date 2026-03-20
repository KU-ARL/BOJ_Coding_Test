#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1005][1005];
int vis[1005][1005];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    for(int i=0; i<n; i++) {
        fill(vis[i], vis[i]+m, -1);
    }

    queue<pair<int, int>> Q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j]==1) {
                vis[i][j]=0;
                Q.push({i, j});
            } else if (board[i][j]==-1) {
                vis[i][j]=-2;
            }
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]!=0 || vis[nx][ny]!=-1) continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j]==-1) {
                cout << -1;
                return 0;
            }

            ans = max(ans, vis[i][j]);
        }
    }

    cout << ans;

}