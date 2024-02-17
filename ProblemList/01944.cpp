#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // monotonic stack
        vector<int> ans(heights.size(),0);
        stack<int> ms;
        for(int i=0; i<heights.size(); ++i){
            while(!ms.empty() && heights[ms.top()] <= heights[i]){
                ans[ms.top()] += 1;
                ms.pop();
            }
            if(!ms.empty()) ans[ms.top()] += 1;
            ms.push(i);
        }
        return ans;
    }
};