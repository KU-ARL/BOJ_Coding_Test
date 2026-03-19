#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[26][26];
int vis[26][26];

vector<int> result;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        string input;
        cin >> input;
        for(int j=0;j<N;j++) {
            board[i][j] = input[j] - '0';
        }
    }

    int num=0;

    queue<pair<int, int>> Q;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j]==1 && vis[i][j]==0) {
                num++;
                Q.push({i, j});
                vis[i][j] = num;

                int cnt=1;

                while(!Q.empty()) {

                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for(int i=0; i<4;i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];

                        if(nx<0||nx>=N||ny<0||ny>=N) continue;
                        if(board[nx][ny]==0 || vis[nx][ny]!=0) continue;

                        Q.push({nx, ny});
                        vis[nx][ny] = vis[cur.X][cur.Y];
                        cnt++;
                    }
                }

                result.push_back(cnt);
            }
        }
    }

    cout << num << '\n';

    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++) cout << result[i] << '\n';
}