#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic stack
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(),0);
        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                ans[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push(make_pair(temperatures[i],i));
        }
        return ans;
    }
};