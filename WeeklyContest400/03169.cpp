#include <vector>
using namespace std;
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        int ans = meetings[0][0] - 1, end = meetings[0][1];
        for(int i=1; i<meetings.size(); i++){
            if(end >= meetings[i][0]){
                end = max(end, meetings[i][1]);
            }else{
                ans += meetings[i][0] - end - 1;
                end = meetings[i][1];
            }
        }
        return ans + max(0, days - end);
    }
};