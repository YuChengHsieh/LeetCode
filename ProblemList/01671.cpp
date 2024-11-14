#include <vector>
using namespace std;

// LIS
class Solution {
private:
    void bs(int val, vector<int>& vec){
        int start = 0, end = vec.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val > vec[mid]) start = mid + 1;
            else end = mid - 1;
        }
        if(start >= vec.size()) vec.push_back(val);
        else vec[start] = val;
        return;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> inc, inc2;
        vector<pair<int,int>> inc_vec1, inc_vec2;
        for(int i=0; i<nums.size(); i++){
            bs(nums[i], inc);
            inc_vec1.push_back({inc.size(),inc.back()});
        }

        reverse(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            bs(nums[i], inc2);
            inc_vec2.push_back({inc2.size(),inc2.back()});
        }

        int ans = 0;
        for(int i=1; i<nums.size()-1; i++){
            int idx = nums.size()-i-1;
            if(inc_vec1[i].first >= 2 && inc_vec2[idx].first >= 2){
                ans = max(ans, 
                inc_vec1[i].second == inc_vec2[idx].second ? inc_vec1[i].first + inc_vec2[idx].first - 1
                : inc_vec1[i].first + inc_vec2[idx].first);
            }
        }
        return nums.size() - ans;
    }
};