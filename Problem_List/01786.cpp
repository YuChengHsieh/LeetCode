#include <vector>
#include <queue>
#include <math.h>
using namespace std;
class Solution {
private: 
    int dijkstra(vector<vector<pair<int,int>>> &graph, int n){
        int mod = pow(10,9)+7;
        vector<int> dist(n,INT_MAX);
        vector<int> mem(n,-1);
        dist[n-1] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({-dist[n-1],n-1});

        while(pq.size() != 0){
            
            while(mem[pq.top().second] != -1){
                pq.pop();
            }
            auto ret = pq.top();
            pq.pop();
            int min = -ret.first, curn = ret.second;

            int ans = 0;
            for(const auto &j: graph[curn]){
                int nextn = j.first, weight = j.second;
                if(mem[nextn] != -1 && dist[nextn] < min){
                    if(nextn == n-1) ans += 1;
                    else ans += mem[nextn]; 
                    ans %= mod;
                }
                else if(mem[nextn] == -1 && dist[curn]+weight < dist[nextn]){
                    dist[nextn] = dist[curn]+weight;
                    pq.push({-(dist[curn]+weight),nextn});
                } 
            }
            mem[curn] = ans;
            if(curn == 0) break;
        }
        return mem[0];
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>());
        for(const auto & edge : edges){
            graph[edge[0]-1].push_back(make_pair(edge[1]-1,edge[2]));
            graph[edge[1]-1].push_back(make_pair(edge[0]-1,edge[2]));
        }
        // dijkstra
        return dijkstra(graph,n);
    }
};