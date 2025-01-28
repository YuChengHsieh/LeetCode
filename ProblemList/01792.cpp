#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    double calRank(double a, double b){
        return (a+1)/(b+1) - a/b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;
        for(auto& c: classes){
            pq.push({calRank(c[0],c[1]),{c[0],c[1]}});
        }
        for(int i=0; i<extraStudents; i++){
            auto [_, val] = pq.top();
            auto [n,d] = val;
            pq.pop();
            pq.push({calRank(n+1,d+1), {n+1,d+1}});
        }
        
        double avgs = 0, cnt = 0;
        while(!pq.empty()){
            auto [_ , val] = pq.top();
            auto [n,d] = val;
            pq.pop();
            avgs += (double)n/(double)d;
            cnt ++;
        }
        return avgs/cnt;
    }
};