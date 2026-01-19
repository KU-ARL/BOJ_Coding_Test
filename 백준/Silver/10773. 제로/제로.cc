#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> S;
  int N;
  cin >> N;

  while(N--) {
    int input;
    cin >> input;

    if (input != 0) {
      S.push(input);
    } else {
      S.pop();
    }
  }

  long long total = 0;

  while(S.size()!=0) {
    total += S.top();
    S.pop();
  }

  cout << total;
}