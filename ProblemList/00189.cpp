#include <queue>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> q;
        auto n = nums.size();
        k %= n;
        
        for(int i=0; i<n-k; i++){
            q.push(nums[i]);
        }
        
        int idx = 0;
        for(; idx<k; idx++){
            nums[idx] = nums[idx+n-k];
        }
        while(!q.empty()){
            nums[idx] = q.front();
            q.pop();
            idx += 1;
        }
    }
};