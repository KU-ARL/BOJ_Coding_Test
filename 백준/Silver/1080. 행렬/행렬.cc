#include <bits/stdc++.h>
using namespace std;


int A[51][51];
int B[51][51];


void flip(int x, int y) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(A[x+i][y+j]==0) A[x+i][y+j]=1;
            else A[x+i][y+j]=0;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;



    for(int i=0; i<N; i++) {
        string row;
        cin >> row;
        for (int j=0; j<M; j++) {
            A[i][j] = row[j] - '0';
        }
    }

    for(int i=0; i<N; i++) {
        string row;
        cin >> row;
        for (int j=0; j<M; j++) {
            B[i][j] = row[j] - '0';
        }
    }

    int count = 0;

    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-2;j++) {
            if(A[i][j] != B[i][j]) {
                flip(i, j);
                count++;
            }
        }
    }

    bool possible = true;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(A[i][j] != B[i][j]) possible = false;
        }
    }

    if(possible) cout << count;
    else cout << -1;

    return 0;

}