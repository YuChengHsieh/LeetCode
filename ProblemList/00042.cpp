#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> ms;
        int area = 0;
        int prev_height = 0;
        for(int i=0; i< height.size(); i++){
            while(!ms.empty() && height[ms.top()] <= height[i]){
                area += (i-ms.top()-1)*(height[ms.top()]-prev_height);
                prev_height = height[ms.top()];
                ms.pop();
            }
            if(!ms.empty()) area += (i-ms.top()-1)*(height[i]-prev_height);
            prev_height = 0;
            ms.push(i);
        }
        return area;
    }
};