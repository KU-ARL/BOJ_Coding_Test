#include <bits/stdc++.h>
using namespace std;


const int MX = 600005;
char dat[MX]; 
int pre[MX], nxt[MX];
int unused = 1;


void insert(int addr, char num) {
  dat[unused]=num;
  nxt[unused]=nxt[addr];
  pre[unused]=addr;

  if(nxt[addr]!=-1) pre[nxt[addr]]=unused;
  nxt[addr]=unused;

  unused++;
}

void erase(int addr) {
  if(nxt[addr]!=-1) pre[nxt[addr]]=pre[addr];
  nxt[pre[addr]]=nxt[addr];
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

  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);

  string S;
  cin >> S;

  int t = 0;

  for(auto s: S) {
    insert(t, s);
    t=nxt[t];
  }

  int N;
  cin >> N;

  for(int i=0; i<N; i++) {
    char input;
    cin >> input;

    if(input=='L') {
      if(pre[t]!=-1) t=pre[t];
    } else if (input=='D') {
      if(nxt[t]!=-1) t=nxt[t];
    } else if (input=='B') {
      if(t!=0) {
        erase(t);
        t=pre[t];
      }
    } else if (input=='P') {
      char w;
      cin >> w;

      insert(t, w);
      t=nxt[t];
    }
  }

  traverse();

}