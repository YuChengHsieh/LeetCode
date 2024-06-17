#include <vector>
using namespace std;
class Solution {
private:
    int inf = 10000000;
    int dp(int idx, int k, int last_idx, vector<int>& nums, vector<vector<vector<int>>>& mem){
        if(k < 0) return -inf;
        if(idx == nums.size()) return 0;
        if(mem[idx][k][last_idx] != -1) return mem[idx][k][last_idx];
        int ans = 0;        
        if(nums[idx] == nums[last_idx]){
            ans = max(ans, dp(idx+1,k,idx,nums,mem)+1);
        } 
        else{
            ans = max(ans, dp(idx+1,k-1,idx,nums,mem)+1);
            ans = max(ans, dp(idx+1,k,last_idx,nums,mem));
        }
        return mem[idx][k][last_idx] = ans;
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<vector<int>>> mem(nums.size(), vector<vector<int>>(k+1, vector<int>(nums.size(),-1)));
        int max_val = 0;
        for(int i=0; i<nums.size(); i++){
            max_val = max(max_val, dp(i+1,k,i,nums,mem)+1);
        }
        return max_val;
    }
};