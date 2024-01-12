#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero_idx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[non_zero_idx] = nums[i];
                non_zero_idx += 1;
            }
        }
        for(int i=non_zero_idx; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};