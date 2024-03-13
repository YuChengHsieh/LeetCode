#include<vector>
using namespace std;
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // int size = min(nums1.size(), num2.size());
        int idx1 = 0, idx2 = 0;   
        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] == nums2[idx2]) return nums1[idx1];
            else if(nums1[idx1] > nums2[idx2]) idx2 += 1;
            else idx1 += 1;
        }
        return -1;
    }
};