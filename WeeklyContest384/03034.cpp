#include <vector>
using namespace std;
// KMP
class Solution {
private:
    vector<int> cal_lps(vector<int> const &pattern){
        int n = pattern.size();
        vector<int> lps(n,0);
        int prev = 0, idx = 1;
        
        while(idx < n){
            if(pattern[idx] == pattern[prev]){
                lps[idx] = prev+1;
                prev += 1; idx += 1;
            }else if(prev == 0){
                idx += 1;
            }else prev = lps[prev-1];
        }
        return lps;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] > 0) nums[i] = 1;
            else if(nums[i+1]-nums[i] < 0) nums[i] = -1;
            else nums[i] = 0;
        }
        
        int ans = 0;
        vector<int>lps = cal_lps(pattern);
        int nums_idx = 0, pattern_idx = 0;
        while(nums_idx < nums.size()-1){
            if(nums[nums_idx] == pattern[pattern_idx]){
                nums_idx += 1;
                pattern_idx += 1;
            }else if(pattern_idx == 0) nums_idx += 1;
            else pattern_idx = lps[pattern_idx-1];
            
            if(pattern_idx == pattern.size()){
                ans += 1;
                pattern_idx = lps[pattern_idx-1];
            }
        }
        
        return ans;
        
    }
};