#include <vector>
using namespace std;

// pick finding o(nlogn)
class Solution {
private:
    long long bs(int val, vector<int>& nums){
        long long cnt = 0;
        for(auto&num: nums){
            cnt += abs((long long)val-(long long)num);
        }
        return cnt;
    }
public:
    int minMoves2(vector<int>& nums) {
        // pick finding
        int min_num = INT_MAX, max_num = INT_MIN;
        for(auto& num: nums){
            min_num = min(min_num,num);
            max_num = max(max_num,num);
        }
        long long start = min_num, end = max_num;

        while(start <= end){
            long long mid = start + (end-start)/2;
            long long mid_val = bs(mid,nums);
            if(bs(mid-1,nums) < mid_val) end = mid - 1;
            else if(bs(mid+1,nums) < mid_val) start = mid + 1;
            else return mid_val;
        }
        return bs(start,nums);
    }
};

// find median o(nlogn)
class Solution {
private:
    int convert(int val, vector<int>& nums){
        int cnt = 0;
        for(auto&num : nums){
            cnt += abs(num-val);
        }
        return cnt;
    }
public:
    int minMoves2(vector<int>& nums) {
        // find median
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n%2 != 0) return convert(nums[n/2],nums);
        else return min(convert(nums[n/2],nums),convert(nums[n/2-1],nums));
    }
};