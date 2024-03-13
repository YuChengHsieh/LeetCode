#include<vector>
using namespace std;
// given start and end, there will no element inside [start, end] and not be chosen.

// tabulation o(nums.size()*k)
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        // DP
        long long long_min = -1e15;
        vector<vector<long long>> dp(k, vector<long long>(nums.size(), long_min));

        for(int i=0; i<nums.size(); i++){
            dp[0][i] = (long long)nums[i]*k;
        }

        for(int i=0; i<k; i++){
            long long step = k-i;
            long long time = i%2 == 0 ? 1 : -1;
            for(int j=i; j<nums.size(); j++){
                long long add_val = (long long)nums[j]*step*time;
                if(i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + add_val);
                if(j > 0) dp[i][j] = max(dp[i][j],dp[i][j-1] + add_val);
                
            }
        }
        long long ans = long_min;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans,dp[k-1][i]);
        }
        return ans;
    }
};

// memorization, time complexity o(k*nums.size())
class Solution {
private:
    long long inf = -1e15;
    long long orig_k;
    long long dp(int idx, long long k, vector<int>& nums, vector<vector<long long>>& mem){
        if(k == 0) return 0LL;
        else if(idx >= nums.size()) return inf;
        if(mem[k-1][idx] != inf) return mem[k-1][idx];
        long long time = k%2 == 1 ? 1LL : -1LL;
        long long ans;
        if(k == orig_k) ans = nums[idx]*k*time;
        ans = max(dp(idx+1, k,  nums, mem), dp(idx+1, k-1, nums, mem)) + nums[idx]*k*time;
        mem[k-1][idx] = ans; 
        return mem[k-1][idx];
    }
public:
    long long maximumStrength(vector<int>& nums, int k) {
        // memorization 
        vector<vector<long long>> mem(k, vector<long long >(nums.size(), inf));
        orig_k = k;
        dp(0, k, nums, mem);
        
        long long max_val = inf;
        for(int i=0; i<nums.size(); i++){
            max_val = max(max_val,mem[orig_k-1][i]);
        }
        return max_val;
    }
};