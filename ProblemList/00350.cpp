#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> nums1_map, nums2_map;
        for(auto& num: nums1){
            nums1_map[num] += 1;
        }
        
        for(auto& num: nums2){
            nums2_map[num] += 1;
        }

        for(auto& num: nums1_map){
            for(int i=0; i<min(num.second,nums2_map[num.first]); i++){
                ans.push_back(num.first);
            }
        }

        return ans;
    } 
};