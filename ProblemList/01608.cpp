#include <vector>
using namespace std;

// o(n) traversal
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lower = 0;
        for(int i=0; i<nums.size(); i++){
            if(i != 0 && nums[i-1] == nums[i]) continue;
            if(nums[i] >= nums.size()-i){
                if(lower > nums.size()-i) return -1;
                else return nums.size()-i;
            }
            lower = nums[i]+1;
        }
        return -1;
    }
};

// o(nlogn) binary search
class Solution {
private:
    int check(int target, vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= target) return nums.size()-i;
        }
        return 0;
    }
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0, end = nums.size();
        while(start <= end){
            int mid = start + (end-start)/2;
            int val = check(mid, nums);
            if(val == mid) return mid;
            else if(val > mid) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};