#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    void dijkstra(int n, vector<vector<int>>& edges, vector<vector<int>>& dist, int source, int destination, int target, bool run, int diff){
        vector<vector<vector<int>>> graph(n);
        int idx = 0;
        for(auto& e: edges){
            graph[e[0]].push_back({e[1], e[2], idx});
            graph[e[1]].push_back({e[0], e[2], idx});
            idx ++;
        }

        dist[source][run] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,source});

        while(!pq.empty()){
            auto [dis,curn] = pq.top();
            pq.pop();
            if(dis > dist[curn][run]) continue;

            for(auto& next: graph[curn]){
                int nextn = next[0], next_dis = next[1], edge_idx = next[2];
                if(next_dis == -1) next_dis = 1;


                if(run && edges[edge_idx][2] == -1){
                    int new_dis = diff + dist[nextn][0] - dist[curn][1];

                    if(new_dis > next_dis){
                        edges[edge_idx][2] = next_dis = new_dis;
                    } 
                }

                if(dist[nextn][run] > dist[curn][run] + next_dis){
                    dist[nextn][run] = dist[curn][run] + next_dis;
                    pq.push({dist[nextn][run],nextn});    
                }
            }
        }
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> dist(n,vector<int>(2,INT_MAX));
        dijkstra(n,edges,dist,source,destination,target,false,0);
        int diff = target - dist[destination][0];
        if(diff < 0) return {};
        dijkstra(n,edges,dist,source,destination,target,true,diff);
        if(dist[destination][1] < target) return {};
        for(auto& e: edges){
            if(e[2] == -1) e[2] = 1;
        }
        return edges;
    }
};