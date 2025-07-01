#include <vector>
using namespace std;
class Solution {
private:
    int bs(long long target, long long num1, vector<int>& nums2){
        int start = 0, end = nums2.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if( (num1 >= 0 && nums2[mid] * num1 <= target) || 
            (num1 < 0 && nums2[mid] * num1 > target)) start = mid + 1;
            else end = mid - 1;
            
        }
        return num1 >= 0 ? start : nums2.size() - start;
    }
    long long check(long long target, vector<int>& nums1, vector<int>& nums2){
        long long ans = 0;
        for(auto& num: nums1){
            ans += bs(target,num,nums2);
        }
        return ans;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long start = -1e10, end = 1e10;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(check(mid,nums1, nums2) < k) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
};