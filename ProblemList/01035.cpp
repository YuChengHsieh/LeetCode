#include <vector>
using namespace std;
class Solution {
private:
    int inf = 1000000;
    int rec(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& mem){
        // knapsack
        if(idx1 == mem.size() || idx2 == mem[0].size()) return 0;
        if(mem[idx1][idx2] != -1) return mem[idx1][idx2];
        int ans = -inf;
        if(nums1[idx1] == nums2[idx2]) ans = max(ans,rec(idx1+1, idx2+1, nums1, nums2, mem)+1);
        else {
            ans = max(rec(idx1+1, idx2, nums1, nums2, mem), rec(idx1, idx2+1, nums1, nums2, mem));
        }
        return mem[idx1][idx2] = ans;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> mem(nums1.size(), vector<int>(nums2.size(),-1));
        return rec(0,0,nums1,nums2,mem);
    }
};