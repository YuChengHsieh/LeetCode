#include <vector>
using namespace std;
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0], ans = 0;
        for(int i=1; i<nums.size(); i++){
            if(prev == nums[i]) ans ^= nums[i];
            prev = nums[i];
        }
        return ans;
    }
};