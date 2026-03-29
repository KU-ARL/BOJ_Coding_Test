#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<bool> v;

    v.push_back(false);

    for(int i=0; i<N; i++) {
        bool input;
        cin >> input;
        v.push_back(input);
    }

    int M;
    cin >> M;

    while(M--) {
        int gender, num;
        cin >> gender >> num;

        if(gender == 1) {
            for(int i=1; i<=N;i++) {
                if(i%num == 0) v[i] = !v[i];
            }
        } else if(gender == 2) {
            v[num] = !v[num];
            for(int i=1;i<N;i++) {
                if(num - i < 1 || num + i > N) break;
                else {
                    if(v[num-i] == v[num+i]) {
                        v[num-i] = !v[num-i];
                        v[num+i] = !v[num+i];
                    } else break;

                }
            }
        }
    }
    for(int i=1; i<v.size();i++) {
        if(i!=1 && i%20 == 1) cout << '\n' << v[i] << ' ';
        else cout << v[i] << ' ';
    }
}

