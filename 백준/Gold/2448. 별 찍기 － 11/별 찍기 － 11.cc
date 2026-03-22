#include <bits/stdc++.h>
using namespace std;

int board[6145][6145]; // max: 3*1024*2 == 6144

void tri(int n, int x, int y) {
    if(n==3) {
        board[x][y] = 1;
        board[x+1][y-1] = 1;
        board[x+1][y+1] = 1;
        for (int i=-2; i<=2; i++) {
            board[x+2][y+i] = 1;
        }

    } else {
        tri(n/2, x, y);
        tri(n/2, x + n/2, y - n/2);  // triangle at left-down
        tri(n/2, x + n/2, y + n/2);  // triangle at right-down
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    tri(N, 1, N);

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N*2;j++) {
            if(board[i][j] == 0) cout << ' ';
            else cout << '*';
        }

        cout << '\n';
    }
}