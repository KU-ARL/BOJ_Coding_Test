#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  int MX=10000;
  int dat[2*MX+1];
  int head = MX, tail = MX;

  while(N--) {
    string op;
    cin >> op;

    if(op=="push_front") {
      int input;
      cin >> input;
      dat[--head] = input;
    } else if (op=="push_back") {
      int input;
      cin >> input;
      dat[tail++] = input;
    } else if (op=="pop_front") {
      if(tail-head) cout << dat[head++] << '\n';
      else cout << -1 << '\n';
    } else if (op=="pop_back") {
      if(tail-head) {cout << dat[tail-1] << '\n'; tail--;}
      else cout << -1 << '\n';
    } else if (op=="size") {
      cout << tail-head << '\n';
    } else if (op=="empty") {
      if(tail-head) cout << 0 << '\n';
      else cout << 1 << '\n';
    } else if (op=="front") {
      if(tail-head) cout << dat[head] << '\n';
      else cout << -1 << '\n';
    } else if (op=="back") {
      if(tail-head) cout << dat[tail-1] << '\n';
      else cout << -1 << '\n';
    }

  }
}