#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n,0);
        int ans = 0;
        for(int i=0; i<m; i++){
            
            // update heights
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            stack<int> st;
            vector<int> left(n,-1);
            vector<int> right(n,n);

            for(int j=n-1; j>=0; j--){
                while(!st.empty() && heights[st.top()] > heights[j]){
                    left[st.top()] = j;
                    st.pop();
                }
                st.push(j);
            }

            while(!st.empty()) st.pop();

            for(int j=0; j<n; j++){
                while(!st.empty() && heights[st.top()] > heights[j]){
                    right[st.top()] = j;
                    st.pop();
                }
                st.push(j);
            }

            for(int j=0; j<n; j++){
                ans = max(ans, (right[j]-left[j]-1)*heights[j]);
            }
        }
        return ans;
    }
};