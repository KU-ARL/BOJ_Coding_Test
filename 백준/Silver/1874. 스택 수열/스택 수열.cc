#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    stack<int> S;
    vector<char> result;
    
    int current_val = 1; // 다음에 들어갈 숫자 대기
    bool possible = true;

    while (N--) {
        int target;
        cin >> target;

        while (current_val <= target) {
            S.push(current_val);
            result.push_back('+');
            current_val++;
        }

        if (!S.empty() && S.top() == target) {
            S.pop();
            result.push_back('-');
        } else {
            possible = false;
            cout << "NO"; 
            return 0; 
        }
    }

    for (char c : result) {
        cout << c << '\n';
    }

    return 0;
}