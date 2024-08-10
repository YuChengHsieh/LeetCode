#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    void dfs(int curn, int base, vector<vector<int>>& res, vector<vector<int>>& graph){
        for(const auto &nextn: graph[curn]){
            if(res[nextn].size() == 0 || res[nextn].back() != base){
                res[nextn].push_back(base);
                dfs(nextn, base, res, graph);
            } 
        }
        return;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> res(n);

        for(const auto & edge: edges){
            graph[edge[0]].push_back(edge[1]);

        }

        for(int i=0; i<n; i++) dfs(i,i,res,graph);
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    void dfs(int curn){
        if(ans[curn].size() != 0) return;
        for(const auto &nextn: graph[curn]){
            dfs(nextn);
            if(find(ans[curn].begin(),ans[curn].end(),nextn) == ans[curn].end()) ans[curn].push_back(nextn);
            for(const auto& node: ans[nextn]){
                if(find(ans[curn].begin(),ans[curn].end(),node) != ans[curn].end())continue;
                ans[curn].push_back(node);
            }
        }
        sort(ans[curn].begin(),ans[curn].end());
        return;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ans.resize(n);
        graph.resize(n);
        unordered_set<int> set;
        for(int i=0; i<n; i++) set.insert(i);
        for(const auto & edge: edges){
            graph[edge[1]].push_back(edge[0]);
            if(set.count(edge[0]) == 1) set.erase(edge[0]);

        }
        vector<int> roots(set.begin(),set.end());
        for(const auto &root: roots) dfs(root);
        return ans;
    }
};