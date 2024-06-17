#include <vector>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> correct_heights(heights.begin(), heights.end());
        sort(correct_heights.begin(),correct_heights.end());
        int cnt = 0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != correct_heights[i]) cnt++;
        }
        return cnt;
    }
};