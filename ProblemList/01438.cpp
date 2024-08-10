#include <vector>
#include <deque>
using namespace std;

// monotonic stack + deque, store value
class Solution {
public:
    int inf = 1e9;
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, left = 0;
        deque<int> moving_max, moving_min;
        for(int right=0; right < nums.size(); right++){
            while(!moving_max.empty() && moving_max.back() < nums[right]){
                moving_max.pop_back();
            }
            moving_max.push_back(nums[right]);

            while(!moving_min.empty() && moving_min.back() > nums[right]){
                moving_min.pop_back();
            }
            moving_min.push_back(nums[right]);

            if(abs(moving_max.front()-nums[right]) <= limit && abs(moving_min.front()-nums[right]) <= limit){
                ans = max(ans,right-left+1);
            }else{
                while(abs(moving_max.front()-nums[right]) > limit || abs(moving_min.front()-nums[right]) > limit){
                    if(moving_max.front() == nums[left]) moving_max.pop_front();
                    if(moving_min.front() == nums[left]) moving_min.pop_front();
                    left ++;
                }
            }
        }
        return ans;
    }
};

// monotonic stack + deque, store idx
class Solution {
public:
    int inf = 1e9;
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, left = 0;
        deque<int> moving_max, moving_min;
        for(int right=0; right < nums.size(); right++){
            while(!moving_max.empty() && nums[moving_max.back()] <= nums[right]){
                moving_max.pop_back();
            }
            moving_max.push_back(right);

            while(!moving_min.empty() && nums[moving_min.back()] >= nums[right]){
                moving_min.pop_back();
            }
            moving_min.push_back(right);

            if(abs(nums[moving_max.front()]-nums[right]) <= limit && abs(nums[moving_min.front()]-nums[right]) <= limit){
                ans = max(ans,right-left+1);
            }else{
                while(abs(nums[moving_max.front()]-nums[right]) > limit || abs(nums[moving_min.front()]-nums[right]) > limit){
                    if(moving_max.front() == left) moving_max.pop_front();
                    if(moving_min.front() == left) moving_min.pop_front();
                    left ++;
                }
            }
        }
        return ans;
    }
};