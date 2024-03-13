#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        unordered_set<int> nums2_set(nums2.begin(), nums2.end());
        for(auto& num: nums2_set){
            if(nums1_set.count(num)) ans.push_back(num);
        }

        return ans;
    } 
};