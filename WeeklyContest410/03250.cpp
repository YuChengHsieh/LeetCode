#include <vector>
using namespace std;

// memorization o(nums.size()*50*50)
class Solution {
private:
    int mod = pow(10,9) + 7;
    long long dp(int idx, int val, vector<int>& nums, vector<vector<int>>& mem){
        if(idx == nums.size()) return 1;
        else if(mem[idx][val] != -1) return mem[idx][val];
        long long ans = 0;
        for(int i=val; i<=nums[idx]; i++){
            if(idx == 0 || nums[idx-1] - val >= nums[idx] - i){
                ans += dp(idx+1,i,nums,mem);
                ans %= mod;
            }
        }
        return mem[idx][val] = ans;
    }
public:
    int countOfPairs(vector<int>& nums){
        vector<vector<int>> mem(nums.size(), vector<int>(51,-1));
        return dp(0,0,nums,mem);
    }
};