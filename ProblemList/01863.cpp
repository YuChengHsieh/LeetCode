#include <vector>
using namespace std;
class Solution {
private:
    int ans = 0;
    void rec(int idx, int val, vector<int>& nums){
        if(idx == nums.size()){
            ans += val;
            return;
        }
        rec(idx+1,val^nums[idx],nums);
        rec(idx+1,val,nums);
        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        rec(0,0,nums);
        return ans;
    }
};