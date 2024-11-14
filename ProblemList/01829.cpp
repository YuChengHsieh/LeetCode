#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int val = 0;
        for(auto& n: nums){
            val ^= n;
        }
        for(int i=nums.size()-1; i>=0; i--){
            int tmp_val = val;
            int tar = 0;
            for(int j=0; j<maximumBit; j++){
                if(tmp_val % 2 == 0) tar += (1 << j);
                tmp_val /= 2;
            }
            val ^= nums[i];
            ans.push_back(tar);
        }
        return ans;
    }
};