#include <vector>
using namespace std;
/*
solution
[... * * * * * | * * * * * | * * * * | * * * * | * * * ..]
            bad idx                            i
                  min(min_idx, max_idx)
                            max(min_idx, max_idx)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int min_idx = -1, max_idx = -1, bad_idx = -1;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == minK) min_idx = i;
            if(nums[i] == maxK) max_idx = i;
            if(nums[i] < minK || nums[i] > maxK ) bad_idx = i;
            ans += max(0,min(min_idx,max_idx)-bad_idx);
        }
        return ans;
    }
};