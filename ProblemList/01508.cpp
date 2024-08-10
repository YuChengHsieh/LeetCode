#include <vector>
using namespace std;

// sliding window + binary search, o(nlogn)
class Solution {
private:
    int MOD = pow(10,9) + 7;
    pair<int, long long> check(int threshold, vector<int>& nums){
        int cur_val = 0;
        int cnt = 0, left = 0;
        long long sum = 0, running_sum = 0;
        for(int right =0; right < nums.size(); right ++){
            running_sum += (long long)nums[right]*(right-left+1);
            cur_val += nums[right];
            while(cur_val > threshold){
                running_sum -= cur_val;
                cur_val -= nums[left++];
            } 
            cnt += right - left + 1;
            sum += running_sum;
        }
        return {cnt,sum};
    }

    long long bs(int val, vector<int>& nums){
        long long start = 1, end = 0, sum;
        for(auto& num: nums) end += num;
        int cnt;
        while(start <= end){
            long long mid = start + (end-start)/2;
            auto ret = check(mid,nums);
            cnt = ret.first; sum = ret.second;
            if(cnt < val) start = mid + 1;
            else end = mid - 1;
        }
        return sum + (val-cnt)*start;
    }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        return (int)(bs(right,nums)%MOD - bs(left-1,nums)%MOD + MOD)%MOD;
    }
};

// o(n^2)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long ans = 0;
        int MOD = pow(10,9)+7;
        
        vector<int> adds;
        for(int i=0; i<n; i++){
            int cur = 0;
            for(int j=i; j<n; j++){
                cur += nums[j];
                adds.push_back(cur);
            }
        }

        sort(adds.begin(), adds.end());

        for(int i=left-1; i<=right-1; i++){
            ans += adds[i];
            ans %= MOD;
        }
        return ans;
    }
};