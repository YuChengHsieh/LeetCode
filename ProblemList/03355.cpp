#include <vector>
using namespace std;
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // prefix sum
        int n = nums.size();
        vector<int> diff(n+1,0);
        for(auto& q: queries){
            diff[q[0]] ++;
            diff[q[1]+1] --;
        }

        vector<int> prefix(n+1,0);
        prefix[0] = diff[0];
        for(int i=1; i<prefix.size(); i++){
            prefix[i] = prefix[i-1] + diff[i];
        }

        for(int i=0; i<n; i++){
            if(prefix[i] < nums[i]) return false;
        }

        return true;
    }
};