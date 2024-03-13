#include <vector>
#include <unordered_map>
using namespace std;
// sort solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums2;
        for(int i=0; i<nums.size(); i++){
            nums2.push_back({nums[i],i});
        }
        sort(nums2.begin(),nums2.end());
        int left = 0, right = nums.size()-1;
        while(left < right){
            if(nums2[left].first + nums2[right].first == target) return {nums2[left].second, nums2[right].second};
            else if(nums2[left].first + nums2[right].first > target) right -= 1;
            else left += 1;
        }
        return {left,right};
    }
};

// map method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(m.count(target-nums[i]) && i != m[target-nums[i]]) return {i,m[target-nums[i]]};
        }
        return {0,0};
    }
};