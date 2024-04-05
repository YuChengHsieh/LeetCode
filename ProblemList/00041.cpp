#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            long long idx = (long long)nums[i]-1;
            while(idx < nums.size() && idx >= 0 && nums[idx] != idx+1){
                long long tmp_num = nums[idx];
                nums[idx] = idx+1;
                idx = tmp_num-1;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};