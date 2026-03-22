#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int pre = 0;
    int hole_idx = 0;  // After Direction for hole_idx square

    for(int i=0; i<6;i++) {
        int dir, dis; // Direction, Distance
        cin >> dir >> dis;

        v.push_back({dir, dis});

        if(dir == 1 && pre == 4) hole_idx = i;
        else if(dir == 2 && pre == 3) hole_idx = i;
        else if(dir == 3 && pre == 1) hole_idx = i;
        else if(dir == 4 && pre == 2) hole_idx = i;

        pre = dir;

    }

    int a = hole_idx;
    int b, c, d;

    if(hole_idx-1>=0) b = hole_idx-1;
    else b = hole_idx-1 + 6;

    if(hole_idx-3>=0) c = hole_idx-3;
    else c = hole_idx-3 +6;
    
    if(hole_idx-4>=0) d = hole_idx-4;
    else d = hole_idx-4 +6;


    int hole_size = v[a].second * v[b].second;
    int total_size = v[c].second * v[d].second;

    int ans = (total_size - hole_size) * N;

    cout << ans;

}