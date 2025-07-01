#include <vector>
using namespace std;
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff = 0;
        for(int i=1; i<nums.size(); i++){
            max_diff = max(max_diff, abs(nums[i]-nums[i-1]));
        }
        return max(max_diff, abs(nums.back() - nums[0]));
    }
};