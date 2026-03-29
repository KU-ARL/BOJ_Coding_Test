#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int sum[5];
int start[5];
int last[5];

int solution(vector<vector<int>> signals) {
    int answer = 0;
    
    for(int i=0; i<signals.size(); i++) {
        sum[i] = signals[i][0] + signals[i][1] + signals[i][2];
        start[i] = signals[i][0];
        last[i] = signals[i][0] + signals[i][1];
    }
    
    
    
    for(int i=0; i<signals.size(); i++) {
        for(int j=i+1; j<signals.size(); j++) {
            if(sum[i] == sum[j]) {
                if(last[i] <= start[j] || last[j] <= start[i]) return -1; 
            }
        }
    }
    
    int limit = 1;
    for(int i=0; i<signals.size(); i++) {
        limit = lcm(limit, sum[i]);
    }
    
    while(answer <= limit) {
        int cnt = 0;
        for(int i=0; i<signals.size(); i++) {
            if(answer % sum[i] > start[i] && answer % sum[i] <= last[i]) {
                cnt++;
            } else break;
        }
        if(cnt == signals.size()) return answer;
        answer++;
    }

    return -1;
    
}