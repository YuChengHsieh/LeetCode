#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return  vector<int> ({-1,-1});
        int start = 0, end = nums.size()-1;
        // find start pos
        while(start <= end){
            int mid =  start + (end-start)/2;
            if(nums[mid] < target) start = mid+1;
            else end = mid-1;
        }
        if(start >= nums.size() || nums[start] != target) return vector<int> ({-1,-1});
        int ans_start = start;
        // find end pos
        start = 0, end = nums.size()-1;
        while(start <= end){
            int mid =  start + (end-start)/2;
            if(nums[mid] <= target) start = mid+1;
            else end = mid-1;
        }
        return vector<int> ({ans_start,end});
    }
};