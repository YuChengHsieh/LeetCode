#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans = INT_MAX, n = timePoints.size();
        for(int i=1; i<n; i++){
            int time = (stoi(timePoints[i].substr(0,2)) - stoi(timePoints[i-1].substr(0,2)))*60
                    + (stoi(timePoints[i].substr(3,2)) - stoi(timePoints[i-1].substr(3,2)));
            ans = min(ans,time);
        }

        int time = (stoi(timePoints[0].substr(0,2))+24 - stoi(timePoints[n-1].substr(0,2)))*60
                    + (stoi(timePoints[0].substr(3,2)) - stoi(timePoints[n-1].substr(3,2)));
        ans = min(ans,time);
        return ans;
    }
};