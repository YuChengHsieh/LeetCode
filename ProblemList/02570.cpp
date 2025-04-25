#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int id1 = 0, id2 = 0, m = nums1.size(), n = nums2.size();
        while(id1 < m || id2 < n){
            int cur = min( (id1 < m ? nums1[id1][0] : INT_MAX) , (id2 < n ? nums2[id2][0] : INT_MAX));
            int val = 0;
            if(id1 < m && nums1[id1][0] == cur){
                val += nums1[id1][1];
                id1 ++;
            }
            if(id2 < n && nums2[id2][0] == cur){
                val += nums2[id2][1];
                id2 ++;
            }
            ans.push_back({cur,val});
        }
        return ans;
    }
};