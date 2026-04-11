#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int board[50][50];

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;

int N, M;

int min_chi_len = 10000000;

int calChickenLen(void) {
    int sum = 0;

    for (int i=0; i<home.size(); i++) {
        int len=10000000;
        for (int j=0; j<selected.size();j++) {
            len = min(len, abs(home[i].first - selected[j].first) + abs(home[i].second - selected[j].second));
        }
        sum += len;
    }

    return sum;
}

void selectChicken(int idx, int count) {
    if (count == M) {
        min_chi_len = min(min_chi_len, calChickenLen());
    }

    for(int i=idx; i<chicken.size(); i++) {
        selected.push_back(chicken[i]);
        selectChicken(i+1, count+1);
        selected.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
            if(board[i][j]==1) home.push_back({i, j});
            if(board[i][j]==2) chicken.push_back({i, j});
        }
    }
    selectChicken(0, 0);
    cout << min_chi_len;
}