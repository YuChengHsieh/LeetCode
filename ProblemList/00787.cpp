#include <vector>
#include <queue>
using namespace std;

// dijkstra + bfs
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph(n, vector<int>(n,INT_MAX));
        vector<int> dist(n, INT_MAX);
        for(auto& flight: flights){
            graph[flight[0]][flight[1]] = flight[2];
        }
        
        
        queue<pair<int, int>> q;
        q.push({src,0});
        

        while(!q.empty() && k > -1){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [cur, val] = q.front();
                q.pop();
                for(int j=0; j<n; j++){
                    if(graph[cur][j] != INT_MAX && val+graph[cur][j] < dist[j] && 
                    (k > 0 || (k == 0 && j == dst))){
                        dist[j] = val+graph[cur][j];
                        q.push({j,val+graph[cur][j]});
                    } 
                }
            }
            k -= 1;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// memorization 
class Solution {
private:
    int inf = pow(10,8);
    int ds, num_node;
    int dfs(int cur, int k, vector<vector<int>>& graph, vector<vector<int>>& cost, vector<vector<int>>& mem){
        if(cur == ds) return 0;
        if(k < 0) return inf;
        if(mem[cur][k] != -1) return mem[cur][k];
        int min_val = inf;
        for(auto &nextn: graph[cur]) min_val = min(min_val,cost[cur][nextn]+dfs(nextn,k-1,graph,cost,mem));
        mem[cur][k] = min_val;
        return mem[cur][k];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> cost(n, vector<int>(n,inf));
        vector<vector<int>> graph(n, vector<int>());
        for(auto& flight: flights){
            cost[flight[0]][flight[1]] = flight[2];
            graph[flight[0]].push_back(flight[1]);
        }
        vector<vector<int>> mem(n, vector<int>(n,-1));
        // visited.insert(src);
        ds = dst; num_node = n;
        return dfs(src, k, graph, cost, mem) == inf ? -1 : dfs(src, k, graph, cost, mem);
    }
};