#include <vector>
using namespace std;
class Solution {
private:
    vector<int> cur_vec;
    int dfs(int cur, int parent, int k, vector<vector<int>>& graph){
        if(k < 0) return 0;
        int val = 1;
        for(auto nextn: graph[cur]){
            if(nextn != parent) val += dfs(nextn,cur,k-1,graph);
        }
        return val;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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

        int max_cnt = 0;
        for(int i=0; i<n; i++){
            max_cnt = max(max_cnt,dfs(i,-1,k-1,graph2));
        }
        
        vector<int> ans;
        for(int i=0; i<m; i++){
            int val = dfs(i,-1,k,graph1);
            ans.push_back(val + max_cnt);
        }

        return ans;
    }
};