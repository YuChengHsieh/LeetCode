#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> indices;
        for(int i=0; i<n; i++){
            if(nums[i] == key) indices.push_back(i);
        }

        int last = 0;
        for(auto& idx: indices){
            for(int i=max(last,idx-k); i<min(n,idx+k+1); i++){
                ans.push_back(i);
            }
            last = idx+k+1;
        }
        return ans;
    }
};