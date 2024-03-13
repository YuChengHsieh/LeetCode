#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // stack
        stack<int> st;
        vector<int> idxs_arr(heights.size(),0);
        for(int i=0; i<idxs_arr.size(); i++){
            while(!st.empty() &&  heights[st.top()] < heights[i]){
                idxs_arr[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            idxs_arr[st.top()] = st.top();
            st.pop();
        }

        vector<int> ans;
        for(auto& item: queries){
            int largest_idx = max(item[0],item[1]);
            int smallest_idx = min(item[0],item[1]);
            if(largest_idx == smallest_idx || heights[largest_idx] > heights[smallest_idx]) ans.push_back(largest_idx);
            else{
                while(heights[largest_idx] <= heights[smallest_idx]){
                    if(largest_idx == idxs_arr[largest_idx]) break;
                    largest_idx = idxs_arr[largest_idx];
                }
                ans.push_back(heights[largest_idx] > heights[smallest_idx] ? largest_idx : -1);
            }
        }
        return ans;
    }
};