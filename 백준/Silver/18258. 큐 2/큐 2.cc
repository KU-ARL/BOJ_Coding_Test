#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  queue<int> Q;

  while(N--) {
    string op;
    cin >> op;

    if(op == "push") {
      int x;
      cin >> x;
      Q.push(x);
    } else if (op == "pop") {
      if(!Q.empty()) {
        cout << Q.front() << '\n';
        Q.pop();
      } else cout << -1 << '\n';
    } else if (op == "size") {
      cout << Q.size() << '\n';
    } else if (op == "empty") {
      cout << (int)Q.empty() << '\n';
    } else if (op == "front") {
      if(!Q.empty()) cout << Q.front() << '\n';
      else cout << -1 << '\n';
    } else if (op == "back") {
      if(!Q.empty()) cout << Q.back() << '\n';
      else cout << -1 << '\n';
    }

  }
}