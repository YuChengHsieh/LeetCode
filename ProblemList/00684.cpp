#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    set<int> cycle_nodes;
    int cyc_node = -1;
    bool dfs(int node, int parent, vector<set<int>>& graph, vector<bool>& visited){
        bool contains = false;
        for(auto& nextn: graph[node]){
            if(!visited[nextn]){
                visited[nextn] = true;
                auto ret = dfs(nextn,node,graph,visited);
                if(ret) contains = true;
            }else if(nextn != parent && cyc_node == -1){
                cyc_node = nextn;
                contains = true;
            } 
        }
        if(contains) cycle_nodes.insert(node);
        return cyc_node == node ? false : contains;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<set<int>> graph(n+1);
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        visited[1] = true;
        auto _ = dfs(1,-1,graph,visited);
        // for(auto& n: cycle_nodes) cout << n << ' ';
        for(int i=n-1; i>=0; i--){
            if(cycle_nodes.count(edges[i][0]) && cycle_nodes.count(edges[i][1])) return edges[i];
        }
        return {};
    }
};