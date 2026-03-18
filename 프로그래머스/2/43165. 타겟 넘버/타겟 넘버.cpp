#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& nums, int index, int target, int cur_sum ) {
    if(index == nums.size()) {
        if(cur_sum == target) {
            answer++; 
        }
        return;
    }
    
    dfs(nums, index+1, target, cur_sum+nums[index]);
    dfs(nums, index+1, target, cur_sum-nums[index]);
    
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, target, 0);
    return answer;
}