#include <vector>
using namespace std;
class Solution {
private:
    int mod = 1e9+7;
    long long power(int y){
        if(y == 0) return 1;
        long long rec = power(y/2);
        return y%2 ? rec*rec*2%mod : rec*rec%mod;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int val = target - nums[i];
            int start = i, end = n-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(val >= nums[mid]) start = mid + 1;
                else end = mid - 1;
            } 
            long long adder = end - i >= 0 ? power(end - i) : 0;
            ans = (ans + adder)%mod;
        }
        return ans;
    }
};