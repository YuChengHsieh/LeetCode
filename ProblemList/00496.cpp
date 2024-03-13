#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nums2_bound;
        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                nums2_bound[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans;
        for(auto& num: nums1){
            if(!nums2_bound.count(num)) ans.push_back(-1);
            else ans.push_back(nums2_bound[num]);
        }

        return ans;
    }
};