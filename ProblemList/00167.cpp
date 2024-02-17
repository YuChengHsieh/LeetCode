#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(true){
            if(nums[left]+nums[right] == target) break;
            else if (nums[left]+nums[right] > target) right -= 1;
            else left += 1;
        }
        return vector<int>{left+1,right+1};
    }
};