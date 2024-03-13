#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[left] + nums[i] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[left],nums[i],nums[right]});
                    left += 1;
                    while(left < right && nums[left] == nums[left-1]) left += 1;
                } 
                else if(sum > 0) right -= 1;
                else left += 1;
            }
        }
        return ans;
    }
};