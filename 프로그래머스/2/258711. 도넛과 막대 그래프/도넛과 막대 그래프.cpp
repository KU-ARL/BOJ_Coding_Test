#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int result[4];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    map<int, int> ingoing;
    map<int, int> outgoing;
    
    for (auto& e: edges) {
        ingoing[e[1]]++;
        outgoing[e[0]]++;
    }
    
    for (auto& [node, out]: outgoing) {
        if (out >= 2 && ingoing[node] == 0) { // start point
            result[0] = node;
        } else if (out >= 2) { // 8 graph
            result[3]++;
        }
    }
    
    // bar graph
    for (auto& [node, in]: ingoing) {
        if (outgoing[node] == 0) {
            result[2]++;
        }
        
    }
    
    // donut
    result[1] = outgoing[result[0]] - result[2] - result[3];
        
        
    for (int r: result) {
        answer.push_back(r);
    }
    
    return answer;
}
