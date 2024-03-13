#include <vector>
using namespace std;
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // two pointer
        int cur = 0, left = 0, right = 0;
        int max_cnt = 0;
        while(right < nums.size()){
            if((cur & nums[right]) == 0){
                cur |= nums[right];
                right += 1;
            }else{
                max_cnt = max(max_cnt,right-left);
                cur &= ~(nums[left]);
                left += 1;
            }
        }
        return max(max_cnt,right-left);
    }
};