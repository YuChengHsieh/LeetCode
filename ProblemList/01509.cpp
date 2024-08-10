#include <vector>
using namespace std;
class Solution {
private:
    int rec(int start_idx, int end_idx, int k, vector<int>& nums){
        if(k == 0) return start_idx >= end_idx ? 0 : nums[end_idx] - nums[start_idx];
        return min(rec(start_idx+1,end_idx,k-1,nums), rec(start_idx,end_idx-1,k-1,nums));
    }
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return rec(0,nums.size()-1,3,nums);
    }
};