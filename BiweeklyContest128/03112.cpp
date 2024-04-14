#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
// dijkstra + priority queue
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> graph(n);
        unordered_set<int> visited;
        visited.insert(0);
        vector<unordered_map<int,int>> dict(n);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto& edge: edges){
            if(!dict[edge[0]].count(edge[1])){
                dict[edge[0]][edge[1]] = graph[edge[0]].size();
                graph[edge[0]].push_back({edge[1],edge[2]});
            }else{
                graph[edge[0]][dict[edge[0]][edge[1]]].second = min(edge[2],graph[edge[0]][dict[edge[0]][edge[1]]].second);
            }
            
            if(!dict[edge[1]].count(edge[0])){
                dict[edge[1]][edge[0]] = graph[edge[1]].size();
                graph[edge[1]].push_back({edge[0],edge[2]});
            }else{
                graph[edge[1]][dict[edge[1]][edge[0]]].second = min(edge[2],graph[edge[1]][dict[edge[1]][edge[0]]].second);
            }
            
        }
        
        vector<int> ans(n,-1);
        ans[0] = 0;
        for(auto& edge: graph[0]){
            if(edge.second < disappear[edge.first]) pq.push({edge.second,edge.first});
        }
        
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if(visited.count(node)) continue;
            ans[node] = dis;
            visited.insert(node);
            for(auto& edge: graph[node]){
                if(!visited.count(edge.first) && dis+edge.second < disappear[edge.first]) pq.push({dis+edge.second, edge.first});
            }
        }
        
        return ans;
    }
};