#include <vector>
using namespace std;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> nums1, nums2, ans;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(nums1.back() > nums2.back()) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }
        
        for(auto& num: nums1) ans.push_back(num);
        for(auto& num: nums2) ans.push_back(num);
        return ans;
    }
};