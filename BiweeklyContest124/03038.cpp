#include <vector>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 0;
        int score = nums[0] + nums[1];
        for(int i=0; i<nums.size()-1; i += 2){
            if(nums[i]+nums[i+1] == score) ans += 1;
            else return ans;
        }
        return ans;
    }
};