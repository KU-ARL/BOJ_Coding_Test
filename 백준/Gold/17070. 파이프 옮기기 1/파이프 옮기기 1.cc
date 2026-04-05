#include <bits/stdc++.h>
using namespace std;

int board[17][17];
int vis[17][17];

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

    queue<pair<int, pair<int, int>>> Q; // {방향, {좌표}}
    Q.push({1, {1, 2}});                  // 가로방향 + 시작점 위치

    while(!Q.empty()) {

        pair<int, pair<int, int>> cur = Q.front();
        Q.pop();

        int dir = cur.first;
        int dx = cur.second.first;
        int dy = cur.second.second;

        // cout << dir << ',' << dx << ',' << dy << '\n';

        if (dir == 1) {
            if (dx+1 <= N && (dx+1 <= N && dy+1 <=N) && dy+1 <=N) {  // 대각선 가능한가
                if (board[dx][dy+1] + board[dx+1][dy+1] + board[dx+1][dy] == 0) {
                    Q.push({3, {dx+1, dy+1}});
                    vis[dx+1][dy+1] += 1;

                    // cout << dir << ',' << dx << ',' << dy << "1&대각\n";
                }
            }
            
            if (dy+1 <= N && board[dx][dy+1] == 0) {  // 옆으로 가능한가
                Q.push({1, {dx, dy+1}});
                vis[dx][dy+1] +=1;
                // cout << dir << ',' << dx << ',' << dy << "1&옆\n";

            }

            // cout << dir << ',' << dx << ',' << dy << "1끝\n";


        } else if (dir == 2) {  // 세로
            if (dx+1 <= N && (dx+1 <= N && dy+1 <=N) && dy+1 <=N) {  // 대각선 가능한가
                if (board[dx][dy+1] + board[dx+1][dy+1] + board[dx+1][dy] == 0) {
                    Q.push({3, {dx+1, dy+1}});
                    vis[dx+1][dy+1] +=1;
                    // cout << dir << ',' << dx << ',' << dy << "2&대각\n";
                }
            }
            
            if (dx+1 <= N && board[dx+1][dy] == 0) {  // 아래로 가능한가
                Q.push({2, {dx+1, dy}});
                vis[dx+1][dy] +=1;
                // cout << dir << ',' << dx << ',' << dy << "2&아래\n";
            }

            // cout << dir << ',' << dx << ',' << dy << "2끝\n";
        } else if (dir == 3) {  // 대각선
            if (dx+1 <= N && (dx+1 <= N && dy+1 <=N) && dy+1 <=N) {  // 대각선 가능한가
                if (board[dx][dy+1] + board[dx+1][dy+1] + board[dx+1][dy] == 0) {
                    Q.push({3, {dx+1, dy+1}});
                    vis[dx+1][dy+1] +=1;
                    // cout << dir << ',' << dx << ',' << dy << "3&대각\n";
                }
            }
            
            if (dx+1 <= N && board[dx+1][dy] == 0) {  // 아래로 가능한가
                Q.push({2, {dx+1, dy}});
                vis[dx+1][dy] +=1;
                // cout << dir << ',' << dx << ',' << dy << "3&아래\n";
            }

                        
            if (dy+1 <= N && board[dx][dy+1] == 0) {  // 옆으로 가능한가
                Q.push({1, {dx, dy+1}});
                vis[dx][dy+1] +=1;
                // cout << dir << ',' << dx << ',' << dy << "3&옆\n";
            }

            // cout << dir << ',' << dx << ',' << dy << "3끝\n";
        }
    }

    cout << vis[N][N];
}