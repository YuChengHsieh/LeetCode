#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    pair<int,int> rec(int cur, vector<vector<int>>& graph, string& s){
        int max_depth = 0;
        int max_val = 1;

        for(auto& nextn: graph[cur]){
            auto [val,depth] = rec(nextn, graph, s);
            max_val = max(max_val,val);
            if(s[cur] != s[nextn]){
                max_val = max(max_val,depth+max_depth+1);
                max_depth = max(max_depth, depth);
            }
        }
        return{max_val, max_depth+1};
    }
public:
    int longestPath(vector<int>& parent, string s) {
        // dfs
        vector<vector<int>> graph(parent.size(),vector<int>());
        int start_node = -1;
        for(int i=1; i<parent.size(); i++){
            graph[parent[i]].emplace_back(i);
        }

        return rec(0, graph, s).first;
    }
};