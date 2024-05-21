#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> ans(edges.size(),false);
        
        vector<vector<vector<int>>> graph(n);
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2],i});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2],i});
        }
        
        priority_queue<pair<pair<int,int>,vector<int>>, vector<pair<pair<int,int>,vector<int>>>, greater<pair<pair<int,int>,vector<int>>>> pq;
        
        vector<int> dist(n,INT_MAX);
        for(auto& item: graph[0]){
            pq.push({{item[1],item[0]},{item[2]}});
            dist[item[0]] = item[1];
        }
        
        
        dist[0] = 0;
        
        int cut_val = INT_MAX;
        // dijkstra with priority queue
        while(!pq.empty()){
            auto [f,s] = pq.top();
            pq.pop();
            
            if(f.first > cut_val) break;
            if(f.second == n-1){
                cut_val = f.first;
                for(auto& i: s){
                    ans[i] = true;
                }
            } 
            
            for(auto& item: graph[f.second]){
                if(f.first+item[1] <= dist[item[0]]){
                    vector<int> new_s = s;
                    dist[item[0]] = f.first+item[1];
                    new_s.push_back(item[2]);
                    pq.push({{f.first+item[1],item[0]},new_s});
                }
            }
            
        }
        return ans;
    }
};