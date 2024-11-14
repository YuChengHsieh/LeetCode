#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_val = 0;
        for(auto& num: nums){
            total_val += num;
        }
        total_val %= p;
        if(total_val == 0) return 0;

        map<long long,int> mp;
        mp[0] = -1;
        long long cur_val = 0;
        int min_len = nums.size();
        for(int i=0; i<nums.size(); i++){
            cur_val += (long long)nums[i];
            cur_val %= p;
            long long target = (cur_val-total_val+p)%p;
            if(mp.count(target)){
                min_len = min(min_len, i - mp[target]);
            } 
            mp[cur_val] = i;
        }
        return min_len == nums.size() ? -1 : min_len;
    }
};