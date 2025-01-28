#include <map>
#include <vector>
using namespace std;

// only using map
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        long long ans = 0, sum = 0;
        for(int i=0; i<k; i++){
            mp[nums[i]] += 1;
            sum += nums[i];
        }
        if(mp.size() == k) ans = max(ans,sum);
        int left = 0;
        for(int i=k; i<nums.size(); i++){
            mp[nums[left]] -= 1;
            if(mp[nums[left]] == 0) mp.erase(nums[left]);
            sum -= nums[left];
            left ++;
            mp[nums[i]] += 1;
            sum += nums[i];
            if(mp.size() == k) ans = max(ans,sum);
        }
        return ans;
    }
};