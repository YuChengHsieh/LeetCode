#include <vector>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0], diff = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-min_val > diff) diff = nums[i]-min_val;
            min_val = min(min_val, nums[i]);
        }
        return diff == 0 ? -1 : diff;
    }
};