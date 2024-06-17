#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> check;
        int cur = 0, prev = 0;
        for(auto& num: nums){
            cur += num;
            if(check.count(cur%k)) return true;
            check.insert(prev%k);
            prev = cur;
        }
        return false;
    }
};


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefix = 0, zero_cnt = 0;
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero_cnt += 1;
                if(zero_cnt == 2) return true;
                continue;
            }
            zero_cnt = 0;
            prefix += nums[i];
            if(mp.count(prefix%k) && mp[prefix%k] != i-1) return true;
            if(!mp.count(prefix%k)) mp[prefix%k] = i;
        }
        return false;
    }
};
