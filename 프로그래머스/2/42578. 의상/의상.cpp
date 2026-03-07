#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> cnt;
    
    for(int i=0; i<clothes.size();i++) {
        if (cnt.find(clothes[i][1]) == cnt.end()) {
            cnt[clothes[i][1]] = 1;
        } else {
            cnt[clothes[i][1]]++;
        }
    }
    
    for (auto& [s, i] : cnt) {
        answer *= (i + 1); 
    }
    
    answer--;
    
    return answer;
}