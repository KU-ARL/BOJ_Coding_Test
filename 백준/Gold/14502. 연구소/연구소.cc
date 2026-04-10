#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int board[8][8];
int temp[8][8];

vector<pair<int, int>> empty_cell;
vector<pair<int, int>> virus;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void copy_board() {
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            temp[i][j] = board[i][j];
}

int bfs() {
    copy_board();
    int cnt = 0;

    queue<pair<int, int>> Q;

    for (int i=0;i<virus.size();i++) {
        Q.push({virus[i].first, virus[i].second});
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(temp[nx][ny] != 0) continue;

            temp[nx][ny] = 2;
            Q.push({nx, ny});
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(temp[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    N, M;
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) empty_cell.push_back({i, j});
            if(board[i][j] == 2) virus.push_back({i, j});
        }
    }

    int max_empty_cell = 0;

    for(int i=0;i<empty_cell.size();i++) {
        for(int j=i+1;j<empty_cell.size();j++) {
            for(int k=j+1;k<empty_cell.size();k++) {
                if(i==j || j==k || k==i) continue;

                int cnt_empty_cell = 0;

                board[empty_cell[i].first][empty_cell[i].second] = 1;
                board[empty_cell[j].first][empty_cell[j].second] = 1;
                board[empty_cell[k].first][empty_cell[k].second] = 1;

                cnt_empty_cell = bfs();
                max_empty_cell = max(cnt_empty_cell, max_empty_cell);

                board[empty_cell[i].first][empty_cell[i].second] = 0;
                board[empty_cell[j].first][empty_cell[j].second] = 0;
                board[empty_cell[k].first][empty_cell[k].second] = 0;
            }
        }
    }

    cout << max_empty_cell;


}