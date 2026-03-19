#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        pair<int, int> meeting;
        cin >> meeting.first >> meeting.second;
        v.push_back(meeting);
    }

    sort(v.begin(), v.end(), compare);

    int last_time = 0;
    int count = 0;

    for(int i=0; i<N; i++) {
        if(v[i].first >= last_time) {
            count++;
            last_time = v[i].second;
        }
    }

    cout << count;

}