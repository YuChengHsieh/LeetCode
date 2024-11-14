#include <vector>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_val = nums[0], cnt = 0;
        for(auto& val: nums){
            cnt += val-min_val;
        }
        return cnt;
    }
};