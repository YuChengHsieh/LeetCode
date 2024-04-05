#include <vector>
using namespace std;
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for(int left = 0; left < nums.size(); left++){
            int tmp_val = nums[left];
            if(tmp_val >= k) return 1;
            for(int right = left+1; right <nums.size(); right++){
                tmp_val |= nums[right];
                if(tmp_val >= k){
                    ans = min(ans,right-left+1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};