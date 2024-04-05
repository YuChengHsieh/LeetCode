#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0, left = 0, right = 0;
        int product = 1;

        while(right < nums.size()){
            product *= nums[right++];
            while(product >= k) product /= nums[left++];
            ans += right-left;
        }
        return ans;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0, left = 0, right = 0;
        int sum = 1;

        while(right < nums.size() && left < nums.size()){
            if(sum*nums[right] < k){
                sum *= nums[right];
                right += 1;
                ans += right - left;
            }else{
                if(left < right){
                    sum /= nums[left];
                    left += 1;
                }else{
                    left += 1;
                    right = left;
                }
            }
        }
        return ans;
    }
};