#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    my solution
                        [ ... * * * | * * * * * * * | * * * * * * * | * * .... ]
                                   left           right             i
                                  <-|->           <-|->           <-|->
    from position i to   more than k     exact k        exact k-1      elements
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int ans = 0, left = 0, right = 0, prev_val = 0;
        for(int i=0; i<nums.size(); i++){
            // update right
            if(!mp.count(nums[i])){
                mp[nums[i]] += 1;
                if(prev_val != nums[i]) left = right;
                while(mp.size() > k-1){
                    mp[nums[right]] -= 1;
                    if(mp[nums[right]] == 0){
                        prev_val = nums[right];
                        mp.erase(nums[right]);
                    } 
                    right ++;
                }
            }else mp[nums[i]] += 1;
            ans += right - left;
        }
        return ans;
    }
};