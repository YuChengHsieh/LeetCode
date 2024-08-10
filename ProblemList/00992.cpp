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

// calculate less or equal is much easier
class Solution {
private:
    int find(vector<int>& nums, int k){
        int left = 0, ans = 0;
        unordered_map<int,int> mp;
        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]] += 1; 
            while(mp.size() > k){
                mp[nums[left]] -= 1;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums,k) - find(nums,k-1);
    }
};