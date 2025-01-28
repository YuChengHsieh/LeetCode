#include <vector>
using namespace std;
class Solution {
private:
    int check(int val, vector<int>& nums){
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += (nums[i]-1)/val;
        }
        return ans;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // binary search
        int start = 1, end;
        for(auto& n: nums) end = max(end,n);

        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(mid,nums) <= maxOperations) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};