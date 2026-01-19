#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  list<char> L;
  string S;
  cin >> S;
  
  for(auto s: S) L.push_back(s);

  list<char>::iterator t=L.end();

  int N;
  cin >> N;

  for(int i=0; i<N; i++) {
    char C;
    cin >> C;

    if (C == 'L') {
      if(t!=L.begin()) t--;
    } else if (C == 'D') {
      if(t!=L.end()) t++;
    } else if (C == 'B') {
      if(t!=L.begin()) {
        t--;
        t = L.erase(t);
      }
    } else if (C == 'P') {
      char input;
      cin >> input;

      L.insert(t, input);
    }
  }

  for(auto i: L) cout << i;
}