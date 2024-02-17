#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        map<int,vector<int>> map;
        sort(nums.begin(), nums.end());
        for(auto &num: nums){
            // cout << num << endl;
            vector<int> tmp;
            for(auto item: map){
                if(num%item.first == 0 && item.second.size() > tmp.size()){
                    tmp = item.second;
                }
            }
            map[num] = tmp;
            map[num].push_back(num);
        }

        vector<int> ans;
        for(auto item: map){
            if(item.second.size() > ans.size()) ans = item.second;
        }

        return ans;
    }
};

// much faster
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>());
        sort(nums.begin(), nums.end());
        int max_val = 0, max_num = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[i].size() < dp[j].size()) dp[i] = dp[j];
            }
            dp[i].push_back(nums[i]);
            if(dp[i].size() > max_val){
                max_val = dp[i].size();
                max_num = i;
            }
        }


        return dp[max_num];
    }
};