#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  queue<int> Q;

  for( int i=1; i<N+1;i++) {
    Q.push(i);
  }

  for(int j=1; j<N; j++) {
    Q.pop();
    int temp = Q.front();
    Q.pop();
    Q.push(temp);
  }

  cout << (int)Q.front();
}