#include <bits/stdc++.h>
using namespace std;

int map[1001][1001];
int cnt[1001][1001];

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--) {
        int n;
        cin >> n;

        for(int i=0; i<n; i++) fill(cnt[i], cnt[i]+n, -1);

        pair<int, int> start, last;
        cin >> start.first >> start.second;
        cin >> last.first >> last.second;

        queue<pair<int, int>> Q;
        Q.push({start});

        cnt[start.first][start.second] = 0;

        while(!Q.empty()) {

            pair<int, int> cur = Q.front();
            Q.pop();

            if(cur == last) break;

            for(int i=0; i<8; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx>=n || nx<0 || ny>=n || ny<0) continue;
                if(cnt[nx][ny] != -1) continue;

                cnt[nx][ny] = cnt[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }

        cout << cnt[last.first][last.second] << '\n';
    }
}