#include <vector>
using namespace std;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int left = 0, prev = -1;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == prev) left = i;
            ans += i - left + 1;
            prev = nums[i];
        }
        return ans;
    }
};