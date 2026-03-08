#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), [] (const int& a, const int& b) {
        return a>b;
    });
    for(int i=citations[0]; i>0; i--) {
        int cnt = 0;
        while(citations[cnt] >= i) {
            cnt++;
        }
        if(cnt >= i) return i;
        
    }

    return answer;
}