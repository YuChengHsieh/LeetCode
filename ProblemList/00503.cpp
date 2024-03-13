#include <vector>
#include <stack>
using namespace std; 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> ans(nums.size(),-1);
        stack<int> st;

        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        return vector<int>(ans.begin(), ans.begin() + nums.size()/2);
    }
};