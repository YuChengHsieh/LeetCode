#include <vector>
#include <unordered_map>
using namespace std;
// NVIDIA Question
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefix = 0, ans = 0;
        mp[0] = 1;
        for(auto& num: nums){
            prefix += num;
            ans += mp[prefix-k];
            mp[prefix] ++;
        }
        return ans;
    }
};