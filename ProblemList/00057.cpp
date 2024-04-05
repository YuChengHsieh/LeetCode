#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0;
        while(idx < intervals.size() && intervals[idx][1] < newInterval[0]){
            ans.push_back(intervals[idx]);
            idx += 1;
        }

        while(idx < intervals.size() && intervals[idx][0] <= newInterval[1]){
            newInterval = {min(newInterval[0],intervals[idx][0]), max(newInterval[1],intervals[idx][1])};
            idx += 1;
        }
        ans.push_back(newInterval);

        while(idx < intervals.size()){
            ans.push_back(intervals[idx]);
            idx += 1;
        }
        return ans;
    }
};