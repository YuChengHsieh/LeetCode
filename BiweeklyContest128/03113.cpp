#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        // monotonic stack
        stack<int> st;
        long long ans = (long long)nums.size();
        unordered_map<int,int> cnts;
        for(int i=0; i<nums.size(); i++){
            // cout << i << endl;
            while(!st.empty() && nums[i] >= nums[st.top()]){
                if(nums[i] == nums[st.top()]){
                    ans += cnts[nums[i]];
                    break;
                }else{
                    cnts[nums[st.top()]] = 0;
                    st.pop();  
                } 
                
            }
            if(st.empty() || nums[i] != nums[st.top()]) st.push(i);
            cnts[nums[i]] += 1;
        }
        return ans;
    }
};