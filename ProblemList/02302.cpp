#include<vector>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, sum = 0;
        int left = 0, right = 0;

        while(left < nums.size()){
            if(sum*(right-left) < k){
                ans += right-left;
                if(right == nums.size()) break;
                
                sum += nums[right];
                right += 1;
            }else{
                sum -= nums[left];
                left += 1;
            }
        }
        return ans;
    }
};