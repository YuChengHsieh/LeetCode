#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        queue<int> q;
        for(int i=1; i<k-1; i++){
            if(nums[i] != nums[i-1]+1) q.push(i-1);
        }

        vector<int> ans;
        int idx = 0;
        for(int i=k-1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                if(q.empty()) ans.push_back(nums[i]);
                else{
                    ans.push_back(-1);
                } 
            }else{
                ans.push_back(-1);
                q.push(i-1);
            }
            if(!q.empty() && q.front() == idx){
                q.pop();
            } 
            idx ++;
        }
        return ans;
    }
};