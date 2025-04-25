#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

// Bipartite + BFS
class Solution {
private:
    bool invalid = false;
    void cal_colors(int cur, bool color, vector<int>& colors, vector<set<int>>& graph){
        colors[cur] = color;
        for(auto& nextn: graph[cur]){
            if(invalid) return;
            if(colors[nextn] == -1) cal_colors(nextn,!color,colors,graph);
            else if(!color != colors[nextn]) invalid = true;
        }
        return;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> colors(n,-1);
        vector<set<int>> graph(n);
        
        for(auto& e: edges){
            graph[e[0]-1].insert(e[1]-1);
            graph[e[1]-1].insert(e[0]-1);
        }

        for(auto& e: edges){
            if(colors[e[0]-1] == -1) cal_colors(e[0]-1,0,colors,graph);
            if(invalid) return -1;
        }
        
        
        unordered_map<int,pair<int,int>> mp;
        for(int i=0; i<n; i++){
            if(graph[i].size() == 0) continue;
            queue<int> q;
            vector<bool> visited(n,false);
            q.push(i);
            visited[i] = true;
            int dis = 0;
            int cnt = 1;
            int max_val = i;

            while(!q.empty()){
                int sz = q.size();
                for(int i=0; i<sz; i++){
                    int cur = q.front();
                    q.pop();
                    for(auto& nextn: graph[cur]){
                        if(!visited[nextn]){
                            visited[nextn] = true;
                            q.push(nextn);
                            cnt ++;
                            max_val = max(max_val,nextn);
                        }
                    }
                }
                dis++;
            }
            mp[max_val] = {max(dis,mp[max_val].first),cnt};
        }

        int ans = 0, add = n;
        for(auto&item: mp){
            ans += item.second.first;
            add -= item.second.second;
        }

        return ans + add;
    }
};