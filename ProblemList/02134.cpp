#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt_1s = 0;
        for(auto& num: nums){
            if(num == 1) cnt_1s ++;
        }
        
        int cur_1s = 0, swap_cnt = 0;

        int idx = 0;
        for(; idx<cnt_1s; idx++){
            if(nums[idx] == 0) swap_cnt += 1;
        }

        int ans = swap_cnt, left = 0;
        for(;idx<nums.size(); idx++){
            if(nums[idx] == 0) swap_cnt += 1;
            if(nums[left++] == 0) swap_cnt -= 1;
            ans = min(ans,swap_cnt);
        }
        for(int i=0; i<cnt_1s; i++){
            if(nums[i] == 0) swap_cnt += 1;
            if(nums[left++] == 0) swap_cnt -= 1;
            ans = min(ans,swap_cnt);
        }
        return ans;
    }
};