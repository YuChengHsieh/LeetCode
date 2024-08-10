#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // greedy
        int ans = 0;
        queue<int> window; 
        for(int i=0; i<nums.size(); i++){
            if( (nums[i] == 0 && window.size()%2 == 0) || (nums[i] == 1 && window.size()%2 == 1)){
                if(i > nums.size()-k) return -1;
                ans += 1;
                window.push(i+k-1);
            }
            if(!window.empty() && window.front() == i) window.pop();
        }
        return ans;
    }
};