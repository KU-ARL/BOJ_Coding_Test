#include <bits/stdc++.h>
using namespace std;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--) {

        int n, m;
        cin >> n >> m; //  n개의 데이터, m번째 데이터가 관심사

        priority_queue<int> pq;
        queue<pair<int, int>> Q;

        for(int i=0; i<n; i++) {

            int temp;
            cin >> temp;

            if(i == m) Q.push({temp, 1});
            else Q.push({temp, 0});

            pq.push(temp);
        }


        int cnt = 0;
        bool finish = false;

        while(!finish) {
            while (pq.top()!=Q.front().first) {
                pair<int, int> temp = Q.front();
                Q.pop();
                Q.push(temp);
            }

            if (Q.front().second == 1) {
                finish = true;
                cnt++;
                continue;
            } else {
                Q.pop();
                pq.pop();
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
}