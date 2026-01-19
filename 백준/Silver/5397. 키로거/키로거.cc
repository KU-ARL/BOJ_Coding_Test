#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX]; 
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char num) {
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  if(nxt[addr]!=-1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;

  unused++;
}

void erase(int addr) {
  nxt[pre[addr]] = nxt[addr];
  if(nxt[addr]!=-1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
  int cur = nxt[0];
  while(cur!=-1) {
    cout << dat[cur];
    cur = nxt[cur];
  }
}



int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while(N--) {
       
    pre[0] = -1;
    nxt[0] = -1;
    unused = 1;

    string S;
    cin >> S;

    int t=0;

    for(auto s: S) {

      if (s == '<') {
        if(pre[t]!=-1) t=pre[t];
      } else if (s == '>') {
        if(nxt[t]!=-1) t=nxt[t];
      } else if (s == '-') {
        if(t!=0) {
          erase(t);
          t=pre[t];
        }
      } else {
        insert(t, s);
        t=nxt[t];
      }
    }

    traverse();
    cout << '\n';
  }
}

