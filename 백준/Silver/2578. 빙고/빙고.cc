#include <bits/stdc++.h>
using namespace std;

int bingo[5][5];
pair<int, int> coor[25];
int call[25];

bool fin(void) {
    int cnt=0;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5; j++) {
            if(bingo[i][j]!=0) break;
            if(j==4) {
                cnt++;
            }
        }
    }

    for(int i=0;i<5;i++) {
        for(int j=0;j<5; j++) {
            if(bingo[j][i]!=0) break;
            if(j==4) {
                cnt++;
            }
        }
    }

    for(int i=0;i<5;i++) {
        if(bingo[i][4-i]!=0) break;
        if(i==4) {
            cnt++;
        }
    }

    for(int i=0;i<5;i++) {
        if(bingo[i][i]!=0) break;
        if(i==4) {
            cnt++;
        }
    }

    if(cnt>=3) return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            int input;
            cin >> input;
            bingo[i][j] = input;
            coor[input] = {i, j};

        }
    }

    for (int i=0; i<25; i++) {
        cin >> call[i];
    }

    for (int i=0; i<25; i++) {
        bingo[coor[call[i]].first][coor[call[i]].second] = 0;
        if(fin()) {
            cout << i+1;
            return 0;
        }
    }
}