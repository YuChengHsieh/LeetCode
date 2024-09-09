#include <vector>
using namespace std;
class Solution {
private:
    bool check(int val, vector<int>& nums, int k){
        int left = 0, ans = 0;
        for(int right=0; right<nums.size(); right++){
            while(nums[right] - nums[left] > val) left++;
            ans += right-left;
        }
        return ans < k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 1000000;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(mid,nums,k)) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
};