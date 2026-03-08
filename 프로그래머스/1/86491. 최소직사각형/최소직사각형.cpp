#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<int> bigger;
    vector<int> smaller;
    
    for(int i=0; i<sizes.size();i++) {
        sort(sizes[i].begin(), sizes[i].end());
        smaller.push_back(sizes[i][0]);
        bigger.push_back(sizes[i][1]);
    }
    
    sort(smaller.begin(), smaller.end());
    sort(bigger.begin(), bigger.end());
    
    answer = smaller[sizes.size()-1] * bigger[sizes.size()-1];
    
    return answer;
}