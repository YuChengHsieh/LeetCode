#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0;
        while(end < nums.size()){
            if(nums[end] == 0) k -= 1;
            
            if(k < 0){
                if(nums[start] == 0)  k += 1;
                start += 1;
            }
            
            end += 1;
        }
        return end - start;
    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0;
        int len = nums.size();
        int zero_cnt = 0;
        int ans = 0;

        for(int i=0; i<len; i++){
            if(nums[i] == 0) zero_cnt += 1;
            if(zero_cnt > k){
                end = i;
                ans = end;
                break;
            }
        }
        if(zero_cnt <= k) return len;

        bool move_start = true;
        while(end < len && start < len){
            if(move_start){
                while(start < len && nums[start] == 1) start += 1;
                start += 1;
                move_start = false;
            }else{
                end += 1;
                while(end < len && nums[end] == 1) end += 1;
                ans = max(ans,end-start);
                move_start = true;
            }
        }
        return ans;
    }
};
