#include <bits/stdc++.h>
using namespace std;

long long recursion(int N, string s, int index, long long cur_sum) {

    if(index >= N) return cur_sum;

    long long new_sum;


    int next = 0;
    long long next_sum;

    long long res1 = -2e18;
    long long res2 = -2e18;

    if(index+3<N) {
        // 뒤에 두 개 괄호로 묶는 경우 괄호 안의 것 먼저 계산해두기: next
        if (s[index+2] == '+') {
            next = (s[index+1] - '0') + (s[index+3] - '0');
        } else if (s[index+2] == '-') {
            next = (s[index+1] - '0') - (s[index+3] - '0');
        } else if (s[index+2] == '*') {
            next = (s[index+1] - '0') * (s[index+3] - '0');
        }

        if (s[index] == '+') {
            next_sum = cur_sum + next;                  // 뒤에 두 개 괄호로 연산
        } else if (s[index] == '-') {
            next_sum = cur_sum - next;
        } else if (s[index] == '*') {
            next_sum = cur_sum * next;
        }
        
        res1 = recursion(N, s, index + 4, next_sum);

    }


    if(index+1<N) {
        if (s[index] == '+') {
            new_sum = cur_sum + (s[index+1] - '0');     // 바로 뒤에꺼 하나만 연산
        } else if (s[index] == '-') {
            new_sum = cur_sum - (s[index+1] - '0');
        } else if (s[index] == '*') {
            new_sum = cur_sum * (s[index+1] - '0');
        }

        res2 = recursion(N, s, index + 2, new_sum);
    }

    return max(res1, res2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string input;
    cin >> input;

    long long max_sum = -2e18;

    cout << recursion(N, input, 1, input[0] - '0');


}