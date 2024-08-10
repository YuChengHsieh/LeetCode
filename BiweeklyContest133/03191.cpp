#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0; i<n-2; i++){
            if(nums[i] == 0){
                ans += 1;
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 1 ? 0 : 1;
                nums[i+2] = nums[i+2] == 1 ? 0 : 1;
            }
        }
        return (nums[n-2] == 1 & nums[n-1] == 1) ? ans : -1;
    }
};