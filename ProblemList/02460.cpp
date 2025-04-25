#include <vector>
using namespace std;
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int zero_cnt = 0;
        int idx = 0;
        while(idx < nums.size()){
            if(idx +1 < nums.size() && nums[idx] == nums[idx+1]){
                if(nums[idx] == 0) zero_cnt ++;
                else ans.push_back(nums[idx]*2);
                zero_cnt ++;
                idx += 2;
            }else{
                if(nums[idx] == 0) zero_cnt ++;
                else ans.push_back(nums[idx]);
                idx ++;
            } 
        }
        for(int i=0; i<zero_cnt; i++){
            ans.push_back(0);
        }
        return ans;
    }
};