#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    
    set<int> nums;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        for(int i=1; i<numbers.size()+1;i++) {
            nums.insert(stoi(numbers.substr(0, i)));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    for (int n : nums) {
        if(n<2) continue;
        
        bool is_prime = true;
        
        for(int i=2; i*i<=n;i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }
        if(is_prime) answer++;
    }
        
    return answer;
}