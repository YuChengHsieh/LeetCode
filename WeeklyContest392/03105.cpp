#include <vector>
using namespace std;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_inc = 1, max_dec = 1, cur_inc = 1, cur_dec = 1, prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > prev){
                cur_inc += 1;
                cur_dec = 1;
            }else if(nums[i] < prev){
                cur_dec += 1;
                cur_inc = 1;
            }else{
                cur_dec = 1;
                cur_inc = 1;
            }
            prev = nums[i];
            max_inc = max(max_inc,cur_inc);
            max_dec = max(max_dec,cur_dec);
        }
        return max(max_inc,max_dec);
    }
};