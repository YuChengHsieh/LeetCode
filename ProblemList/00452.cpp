#include <vector>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int shoot = 0;
        sort(points.begin(),points.end(),[](vector<int> a, vector<int> b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        
        int shoot_cnt = 0;
        long th = long(INT_MIN)-1;
        for(auto const &point: points){
            if(point[0] > th){
                shoot_cnt += 1;
                th = point[1];
            } 
        }
        return shoot_cnt;
    }
};

// 10 times faster by changing vector to pair to sort
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int shoot = 0;
        vector<pair<int,int>> V;
        for(int i=0; i<points.size(); i++)
        {
            pair<int,int> P = make_pair(points[i][0],points[i][1]);
            V.push_back(P);
        }
        sort(V.begin(),V.end(),[](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });
        
        int shoot_cnt = 0;
        long th = long(INT_MIN)-1;
        for(auto const &point: V){
            if(point.first > th){
                shoot_cnt += 1;
                th = point.second;
            } 
        }
        return shoot_cnt;
    }
};