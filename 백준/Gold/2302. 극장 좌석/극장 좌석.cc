#include <bits/stdc++.h>
using namespace std;

vector<int> vip = {0};
int d[45];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int M;
    cin >> M;

    while(M--) {
        int vip_num;
        cin >> vip_num;
        vip.push_back(vip_num);
    }

    vip.push_back(N+1);

    // for(int i=0 ; i<vip.size();i++) cout << i << ": " << vip[i] << '\n';

    d[1] = 1;
    d[0] = 1;
    d[2] = 2;
    for(int i=3; i<45; i++) d[i] = d[i-1] + d[i-2];

    // for(int i=0 ; i<7;i++) cout << i << ": " << d[i] << '\n';

    int result = 1;

    for (int i=0; i<vip.size()-1; i++) {
        // cout << vip[i+1]-vip[i]-1 << '\n';
        // cout << d[vip[i+1]-vip[i]-1] << '\n';
        result *= d[vip[i+1]-vip[i]-1];
    }

    cout << result;
}