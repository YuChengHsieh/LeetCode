#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = n-1;
                while(left < right){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left += 1;
                        while(left < right && nums[left] == nums[left-1]) left += 1;
                    }else if(sum < target) left += 1;
                    else right -= 1;

                }
            }
        }
        return ans;
    }
};