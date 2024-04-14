#include <vector>
using namespace std;
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        long long cnt = 0;
        
        for(int i=sz/2; i>=0; i--){
            if(nums[i] > k) cnt += nums[i]-k;
            else break;
        }
        
        for(int i=sz/2; i<sz; i++){
            if(nums[i] < k) cnt += k-nums[i];
            else break;
        }
        return cnt;
    }
};