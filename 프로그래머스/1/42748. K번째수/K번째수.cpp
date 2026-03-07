#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++) {
        int size = commands[i][1]-commands[i][0]+1;
        vector<int> slice(size, 0);
        int idx = 0;
        for(int j=commands[i][0]-1; j<commands[i][1]; j++) {
            slice[idx] = array[j];
            idx++;
        }
        
        sort(slice.begin(), slice.end());
        
        answer.push_back(slice[commands[i][2]-1]);
    }
    
    return answer;
}