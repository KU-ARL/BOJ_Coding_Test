#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

vector<set<int>> s(9);


int solution(int N, int number) {
    
    if(N==number) return 1;
    
    s[1].insert(N);
    
    int rec = N;
    
    for (int i=2;i<=8;i++) {
        for (int j=1; j<i;j++) {
            for (int n: s[j]) {
                for (int m: s[i-j]) {
                    s[i].insert(n+m);
                    if(n-m >0) s[i].insert(n-m);
                    s[i].insert(n*m);
                    if(n%m==0) s[i].insert(n/m);
                }
            }
        }
        
        rec = rec*10 + N;
        s[i].insert(rec);
        
        if(s[i].count(number)) return i;
    }
    
    
    return -1;
    
    
}