#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // queue dijkstra
        vector<vector<int>> graph(n+1);
        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(1);

        int total_time = 0;
        vector<int> dist1(n+1,INT_MAX), dist2(n+1,INT_MAX);
        dist1[1] = 0;

        while(!q.empty()){
            int sz = q.size();
            total_time += time;
            for(int i=0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                for(auto& nextn: graph[cur]){
                    if(dist1[nextn] > total_time){
                        dist1[nextn] = total_time;
                        q.push(nextn);
                    }else if(total_time != dist1[nextn] && dist2[nextn] > total_time){
                        dist2[nextn] = total_time;
                        q.push(nextn);
                    }
                }
            }
            if((total_time/change)%2) total_time = change*(total_time/change+1);
        }
        return dist2[n];
    }
};