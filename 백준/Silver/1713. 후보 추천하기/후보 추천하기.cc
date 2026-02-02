#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    int vote;
    int time;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, T;
    cin >> N >> T;

    vector<Student> frame;

    for (int i = 0; i < T; i++) { 
        int candidate;
        cin >> candidate;

        bool exists = false;
        for (int j = 0; j < frame.size(); j++) {  // 여기에서 매번 후보를 전부 확인하는 행동
            if (frame[j].id == candidate) {
                frame[j].vote++;
                exists = true;
                break;
            }
        }

        if (!exists) {
            if (frame.size() == N) {  // 가득 찼을 때
                sort(frame.begin(), frame.end(), [](const Student& a, const Student& b) {
                    if (a.vote == b.vote) return a.time < b.time;
                    return a.vote < b.vote;
                });
                frame.erase(frame.begin()); // 정렬 후 맨 앞 후보 삭제
            }
            frame.push_back({candidate, 1, i});
        }
    }

    sort(frame.begin(), frame.end(), [](const Student& a, const Student& b) {
        return a.id < b.id;
    });

    for (int i = 0; i < frame.size(); i++) {
        cout << frame[i].id << (i == (int)frame.size() - 1 ? "" : " ");
    }

    return 0;
}