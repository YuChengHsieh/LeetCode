#include<vector>
using namespace std;
class Solution {
private:
    vector<bool> groups; 
    int dfs(int cur, int parent, int depth, bool first, vector<vector<int>>& graph){
        int val = depth%2 ? 0 : 1;
        if(first && depth%2 == 0) groups[cur] = true; 
        for(auto& nextn: graph[cur]){
            if(nextn != parent) val += dfs(nextn,cur,depth+1,first,graph);
        }
        return val;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size()+1, n = edges2.size()+1;
        vector<vector<int>> graph1(m);
        vector<vector<int>> graph2(n);

        for(auto e: edges1){
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }

        for(auto e: edges2){
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        groups = vector<bool>(m,false);

        int group1_val = dfs(0,-1,0,true,graph1);
        int group2_val = dfs(graph1[0][0],-1,0,false,graph1);
        int maxodds_val = max(dfs(0,-1,1,false,graph2),dfs(graph2[0][0],-1,1,false,graph2));

        vector<int> ans;
        for(int i=0; i<m; i++){
            ans.push_back(maxodds_val + (groups[i] ? group1_val : group2_val));
        }
        return ans;  
    }
};

class Solution {
private:
    vector<bool> groups; 
    int dfs(int cur, int parent, int depth, bool first, vector<vector<int>>& graph){
        int val = depth%2 ? 0 : 1;
        if(first && depth%2 == 0) groups[cur] = true; 
        for(auto& nextn: graph[cur]){
            if(nextn != parent) val += dfs(nextn,cur,depth+1,first,graph);
        }
        return val;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size()+1, n = edges2.size()+1;
        vector<vector<int>> graph1(m);
        vector<vector<int>> graph2(n);

        for(auto e: edges1){
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }

        for(auto e: edges2){
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        groups = vector<bool>(m,false);

        int group1_val = dfs(0,-1,0,true,graph1);
        int odds_val = dfs(0,-1,1,false,graph2);
        int maxodds_val = max(odds_val,n-odds_val);

        vector<int> ans;
        for(int i=0; i<m; i++){
            ans.push_back(maxodds_val + (groups[i] ? group1_val : m-group1_val));
        }
        return ans;  
    }
};