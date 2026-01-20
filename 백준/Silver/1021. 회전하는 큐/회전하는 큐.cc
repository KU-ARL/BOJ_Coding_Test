#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  int ans=0;

  deque<int> DQ;

  for(int i=1; i<N+1;i++) {
    DQ.push_back(i);
  }

  while(M--) {
    int input;
    cin >> input;

    int idx = find(DQ.begin(), DQ.end(), input) - DQ.begin();

    while(DQ.front()!=input) {
      if (idx < DQ.size()-idx) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
      } else {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      ans++;
    }

    DQ.pop_front();
  }

  cout << ans;

}