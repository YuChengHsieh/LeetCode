#include <vector>
using namespace std;

class Solution {
private:
    void update_dist(int node, int tar, int tar_cost, vector<vector<int>>& dist){
        int val = 1 + tar_cost + (tar%2 == 0);
        if(val > dist[node][1]){
            dist[node][3] = dist[node][1];
            dist[node][2] = dist[node][0];
            dist[node][1] = val;
            dist[node][0] = tar;
        }else if(val > dist[node][3]){
            dist[node][3] = val;
            dist[node][2] = tar;
        }
        return;
    }
    void dfs1(int node, int parent, vector<vector<int>>& graph, vector<vector<int>>& dist1){
        for(auto& n: graph[node]){
            if(n == parent) continue;   
            dfs1(n,node,graph,dist1);
            update_dist(node,n,dist1[n][1],dist1);
        }
        return; 
    }

    void dfs2(int node, int parent, vector<vector<int>>& graph, vector<vector<int>>& dist1, vector<vector<int>>& dist2){
        if(parent != -1){
            int parent_cost = (dist2[parent][0] == node) ? dist2[parent][3] : dist2[parent][1];
            update_dist(node,parent,parent_cost,dist2);

        }
        for(auto& n: graph[node]){
            if(n == parent) continue;
            dfs2(n,node,graph,dist1,dist2);
        }
    }

public:
    vector<int> ans;
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> graph(n);

        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<vector<int>> dist1(n, vector<int>(4,0)), dist2(n, vector<int>(4,0));
        dfs1(0,-1,graph,dist1);
        dist2 = dist1;
        dfs2(0,-1,graph,dist1,dist2);

        vector<int> ans;
        for(auto& num: dist2){
            ans.push_back(num[1]);
        }

        return ans;
    }
};