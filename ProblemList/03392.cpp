#include <vector>
using namespace std;
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int ans = 0;
            for(int i=2; i<nums.size(); i++){
                ans += !(nums[i-1]%2) && nums[i-2] + nums[i] == nums[i-1]/2;
            }
            return ans;
        }
    };