#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int mat[1000][1000];

    for(int i=0; i<N; i++) {
        string row;
        cin >> row;
        for (int j=0; j<M; j++) {
            mat[i][j] = row[j] - '0';
        }
    }

    // input 잘 받는지 테스트
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; j++) {
    //         cout << mat[i][j];
    //     }
    //     cout << "\n";
    // }

    int max=1;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++){
            for(int k=j+1;k<M;k++) {
                if(mat[i][j] == mat[i][k]) {
                    int distance = k-j;
                    if(i+distance < N && j+distance < M) {
                        if(mat[i][j] == mat[i+distance][j] && mat[i][j] == mat[i+distance][j+distance]) {
                            if(max < (distance+1)*(distance+1)) max = (distance+1)*(distance+1);
                        }
                    }

                }
            }
        }
    }

    cout << max;


    return 0;
}