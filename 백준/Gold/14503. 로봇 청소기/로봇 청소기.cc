#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;

    while (true) {
        if (board[r][c] == 0) {
            board[r][c] = 2;
            cnt++;
        }

        bool has_empty_space = false;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (board[nr][nc] == 0) {
                has_empty_space = true;
                break;
            }
        }

        if (has_empty_space) {
            for (int i = 0; i < 4; i++) {
                d = (d + 3) % 4;
                int nr = r + dx[d];
                int nc = c + dy[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    break;
                }
            }
        } else {
            int back_d = (d + 2) % 4;
            int br = r + dx[back_d];
            int bc = c + dy[back_d];

            if (br < 0 || br >= n || bc < 0 || bc >= m || board[br][bc] == 1) {
                break;
            }
            r = br;
            c = bc;
        }
    }

    cout << cnt;
    return 0;
}