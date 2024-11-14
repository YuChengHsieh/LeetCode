#include <vector>
using namespace std;
class Solution {
private:
    long long SW(int threshold, vector<int>& nums){
        long long cnt = 0;
        for(int left=0, right = nums.size()-1; left<right; left++){
            while(right > left && nums[right]+nums[left] > threshold) right --;
            cnt += right-left;
        }
        return cnt;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return SW(upper,nums) - SW(lower-1,nums);
    }
};