#include <iostream>

using namespace std;

int board[504][504];

void tornado(int x, int y, int dir) {
    // cout << x << ' ' << y << endl;
    if ( dir == 1 ) {
        int temp = board[x][y];
        int sum = 0;
        board[x][y] = 0;

        // 7%
        board[x-1][y] += (temp * 7) / 100;
        board[x+1][y] += (temp * 7) / 100;
        sum += (temp * 7) / 100;
        sum += (temp * 7) / 100;

        // cout << temp << ":  temp" << '\n';
        // cout << (temp * 7) / 100 << " : 7" << '\n';
        // cout << (temp * 2) / 100 << " : 2" << '\n';
        // cout << temp / 100 << " : 1" << '\n';
        // cout << (temp * 10) / 100 << " : 10" << '\n';
        // cout << (temp * 5) / 100 << " : 5" << '\n';

        // 2%
        board[x-2][y] += (temp * 2) / 100;
        board[x+2][y] += (temp * 2) / 100;
        sum += (temp * 2) / 100;
        sum += (temp * 2) / 100;

        // 1%
        board[x-1][y+1] += temp / 100;
        board[x+1][y+1] += temp / 100;
        sum += temp / 100;
        sum += temp / 100;

        // 10%
        board[x-1][y-1] += (temp * 10) / 100;
        board[x+1][y-1] += (temp * 10) / 100;
        sum += (temp * 10) / 100;
        sum += (temp * 10) / 100;

        // 5%
        board[x][y-2] += (temp * 5) / 100;
        sum += (temp * 5) / 100;

        // cout << sum << "summmmmmm" << '\n';


        // alpha
        board[x][y-1] += temp - sum;
    } else if ( dir == 2 ) {
        int temp = board[x][y];
        int sum = 0;
        board[x][y] = 0;

        // 7%
        board[x][y+1] += (temp * 7) / 100;
        board[x][y-1] += (temp * 7) / 100;
        sum += 2* ((temp * 7) / 100);

        // 2%
        board[x][y+2] += (temp * 2) / 100;
        board[x][y-2] += (temp * 2) / 100;
        sum += 2* ((temp * 2) / 100);

        // 1%
        board[x-1][y-1] += temp / 100;
        board[x-1][y+1] += temp / 100;
        sum += 2* (temp / 100);

        // 10%
        board[x+1][y-1] += (temp * 10) / 100;
        board[x+1][y+1] += (temp * 10) / 100;
        sum += 2* ((temp * 10) / 100);

        // 5%
        board[x+2][y] += (temp * 5) / 100;
        sum += (temp * 5) / 100;

        // alpha
        board[x+1][y] += temp - sum;
    } else if ( dir == 3 ) {
        int temp = board[x][y];
        int sum = 0;
        board[x][y] = 0;

        // 7%
        board[x-1][y] += (temp * 7) / 100;
        board[x+1][y] += (temp * 7) / 100;
        sum += 2* ((temp * 7) / 100);

        // 2%
        board[x-2][y] += (temp * 2) / 100;
        board[x+2][y] += (temp * 2) / 100;
        sum += 2* ((temp * 2) / 100);

        // 1%
        board[x-1][y-1] += temp / 100;
        board[x+1][y-1] += temp / 100;
        sum += 2* (temp / 100);

        // 10%
        board[x-1][y+1] += (temp * 10) / 100;
        board[x+1][y+1] += (temp * 10) / 100;
        sum += 2* ((temp * 10) / 100);

        // 5%
        board[x][y+2] += (temp * 5) / 100;
        sum += (temp * 5) / 100;

        // alpha
        board[x][y+1] += temp - sum;
    } else if ( dir == 4 ) {
        int temp = board[x][y];
        int sum = 0;
        board[x][y] = 0;

        // 7%
        board[x][y+1] += (temp * 7) / 100;
        board[x][y-1] += (temp * 7) / 100;
        sum += 2* ((temp * 7) / 100);

        // 2%
        board[x][y+2] += (temp * 2) / 100;
        board[x][y-2] += (temp * 2) / 100;
        sum += 2* ((temp * 2) / 100);

        // 1%
        board[x+1][y-1] += temp / 100;
        board[x+1][y+1] += temp / 100;
        sum += 2* (temp / 100);

        // 10%
        board[x-1][y-1] += (temp * 10) / 100;
        board[x-1][y+1] += (temp * 10) / 100;
        sum += 2* ((temp * 10) / 100);

        // 5%
        board[x-2][y] += (temp * 5) / 100;
        sum += (temp * 5) / 100;

        // alpha
        board[x-1][y] += temp - sum;
    } 

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=2;i<=N+1;i++) {
        for(int j=2;j<=N+1;j++) {
            cin >> board[i][j];
        }
    }

    int dx = 2 + (N / 2);
    int dy = 2 + (N / 2);
    
    int cnt = 1;

    bool is_finish = false;
    while(!is_finish) {
        for(int i=0; i<cnt;i++) {
            dy--;
            tornado(dx, dy, 1);

            if(dx == 2 && dy == 2) {
                // cout << "finish";
                is_finish = true;
                break;
            }
        }
        if(is_finish) break;
        for(int i=0; i<cnt;i++) {
            dx++;
            tornado(dx, dy, 2);
        }
        cnt++;
        for(int i=0; i<cnt;i++) {
            dy++;
            tornado(dx, dy, 3);
        }

        for(int i=0; i<cnt;i++) {
            dx--;
            tornado(dx, dy, 4);
        }
        cnt++;
    }



    int sum = 0;

    for(int i=0; i<2; i++) {  // 위쪽으로 튀어나온 것
        for(int j=0;j<=N+3;j++) {
            sum += board[i][j];
        }
    }

    for(int i=N+2; i<=N+3; i++) {  // 아래으로 튀어나온 것
        for(int j=0;j<=N+3;j++) {
            sum += board[i][j];
        }
    }

    for(int i=2;i<=N+1;i++) {
        sum += board[i][0];
        sum += board[i][1];
        sum += board[i][N+2];
        sum += board[i][N+3];
    }

    cout << sum;

}



