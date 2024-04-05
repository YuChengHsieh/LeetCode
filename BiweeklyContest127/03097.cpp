#include <vector>
using namespace std;
class Solution {
private:
    bool check(vector<int>& bitmask, vector<int>& k_bitmask){
        for(int i=34; i>=0; i--){
            if(k_bitmask[i] > bitmask[i]) return false;
            else if (k_bitmask[i] == 0 && bitmask[i] > k_bitmask[i]) return true;
        }
        return true;
    }

    void changeBitmask(vector<int>& bitmask, int val, bool add){
        int cnt = 0;
        while(val != 0){
            if(val%2 == 1) bitmask[cnt] = add ? bitmask[cnt] + 1 : bitmask[cnt] - 1;
            val /= 2;
            cnt += 1;
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitmask(35,0), k_bitmask(35,0);
        int ans = INT_MAX;
        changeBitmask(k_bitmask, k, true);

        int left = 0;
        for(int i=0; i<nums.size(); i++){
            int tmp_num = nums[i];
            changeBitmask(bitmask, nums[i], true);
            
            while(left <= i && check(bitmask,k_bitmask)){
                ans = min(ans, i-left+1);
                changeBitmask(bitmask, nums[left], false);
                left += 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};