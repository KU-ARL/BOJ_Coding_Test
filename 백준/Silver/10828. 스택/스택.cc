#include <bits/stdc++.h>
using namespace std;

int dat[10005];
int pos = 0;

void push(int x) {
  dat[pos++] = x;
}

void pop(void) {
  if(pos==0) {
    cout << -1 << '\n';
  } else {
    cout << dat[--pos] << '\n';
  }
}

void size(void) {
  cout << pos << '\n';
}

void empty(void) {
  if(pos) cout << 0 << '\n';
  else cout << 1 << '\n';
}

void top() {
  if(pos) cout << dat[pos-1] << '\n';
  else cout << -1 << '\n';
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while(N--) {
    string op;
    cin >> op;
    if ( op == "push") {
      int input;
      cin >> input;

      push(input);
    } else if ( op == "pop") {
      pop();
    } else if ( op == "size") {
      size();
    } else if ( op == "empty") {
      empty();
    } else if ( op == "top") {
      top();
    }
  }

}