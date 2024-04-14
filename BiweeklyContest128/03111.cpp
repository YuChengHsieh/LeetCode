#include <vector>
using namespace std;
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        
        int cnt = 1, first_x = points[0][0];
        for(int i=1; i<points.size(); i++){
            if(points[i][0] - first_x > w){
                cnt += 1;
                first_x = points[i][0];
            }
        }
        return cnt;
    }
};