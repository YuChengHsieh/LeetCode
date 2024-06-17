#include <vector>
using namespace std;

// backtracking
class Solution {
private:
    int ans = 0;
    void rec(int idx, vector<int>& mem, vector<int>& nums, int& k){
        if(idx == nums.size()){
            ans += 1;
            return;
        } 
        if(mem[nums[idx]-k+1000] == 0){
            mem[nums[idx]+1000] += 1;
            rec(idx+1,mem,nums,k);
            mem[nums[idx]+1000] -= 1;
        } 
        rec(idx+1,mem,nums,k);
        return;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> mem(2002,0);
        rec(0,mem,nums,k);
        return ans-1;
    }
};