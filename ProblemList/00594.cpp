#include <vector>
#include <map>
using namespace std;

// o(1) space complexity
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int left = 0, ans = 0;
        for(int right = 0; right < nums.size(); right++){
            while(nums[right] - nums[left] > 1) left ++;
            if(nums[right] - nums[left] == 1) ans = max(ans,right - left + 1);
        }

        return ans;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        map<int,pair<int,int>> mp;
        for(int i=0; i<nums.size(); i++){
            if(!mp.count(nums[i])) mp[nums[i]] = {INT_MAX,-INT_MAX};
            mp[nums[i]] = {min(mp[nums[i]].first,i),max(mp[nums[i]].second,i)};
        }

        int prev = -1e9-1, ans = 0, prev_idx = 0;
        for(auto &item: mp){
            auto [val, minmax] = item;
            if(val - prev == 1){
                ans = max(ans,minmax.second - prev_idx+1);
            }
            prev = val;
            prev_idx = minmax.first;
        }
        return ans;
    }
};