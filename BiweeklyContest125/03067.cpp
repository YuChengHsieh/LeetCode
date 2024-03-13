#include <vector>
using namespace std;
class Solution {
private:
    int dfs(int cur, int parent, int cur_speed, int signalSpeed, vector<vector<int>>& graph, vector<vector<int>>& connected_node){
        int ret = cur_speed%signalSpeed == 0;
        for(auto& nextn: connected_node[cur]){
            if(nextn != parent){
                ret += dfs(nextn, cur, cur_speed+graph[cur][nextn], signalSpeed, graph, connected_node);
            }
        }
        return ret;
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<vector<int>> graph(n, vector<int>(n,INT_MAX));
        vector<vector<int>> connected_node(n);
        vector<int> ans(n,0);
        
        for(auto& edge: edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
            connected_node[edge[0]].push_back(edge[1]);
            connected_node[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++){
            int cnt = 0;
            if(connected_node[i].size() == 1) continue;
            for(auto& nextn: connected_node[i]){
                int val = dfs(nextn, i, graph[i][nextn], signalSpeed, graph, connected_node);
                ans[i] += cnt*val;
                cnt += val;
            }
        }
        return ans;
    }
};