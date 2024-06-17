#include <vector>
using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0, idx = 0;
        long long sum = 0;
        while(sum < n){
            if(idx < nums.size() && sum >= nums[idx]-1){
                sum += nums[idx];
                idx ++;
            }else{
                ans ++;
                sum += sum+1;
            }
        }
        return ans;
    }
};