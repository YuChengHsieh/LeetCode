#include <vector>
using namespace std;
class Solution {
private:
    bool find = false;
    void dfs(int cur, int target, vector<bool>& visited, vector<vector<int>>& graph){
        for(auto& nextn: graph[cur]){
            if(visited[nextn]) continue;
            if(nextn == target) find = true;
            if(find) break;
            visited[nextn] = true;
            dfs(nextn, target, visited, graph);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        if(n == 1) return true;
        dfs(source,destination,visited,graph);
        return find;
    }
};