#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1004][1004];
int vis[1004][1004];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    for(int i=0; i<n; i++) fill(vis[i], vis[i]+m, -1);

    queue<pair<int, int>> Q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];

            if(board[i][j] == 1) {
                Q.push({i, j});
                vis[i][j] = 0;
            }

            if(board[i][j] == -1) {
                vis[i][j] = -2;
            }
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny]==-1 || board[nx][ny]==1 || vis[nx][ny]>0) continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    // cout << "final vis" << '\n';
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << vis[i][j];
    //     }
    //     cout << '\n';
    // }


    int mx = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            mx = max(mx, vis[i][j]);
            if(vis[i][j]==-1) {
                cout << -1;
                return 0;
            }
        }
    }


    cout << mx;

}