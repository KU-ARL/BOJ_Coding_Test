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

  int len = S.size();
  for(int i=0; i<len;i++) {
    total += S.top();
    S.pop();
  }

  cout << total;
}