#include <vector>
using namespace std;
class Solution {
private:
    int count = 0;
    int traverse(int curn, int parent, vector<vector<int>>& graph){
        int ans = 0, sz = -1;
        bool success = true;
        for(auto& nextn: graph[curn]){
            if(nextn == parent) continue;
            int ret = traverse(nextn,curn,graph);
            if(sz == -1) sz = ret;
            else if(sz != ret) success = false;
            ans += ret;
        }
        if(success) count ++;
        return ans+1;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> graph(n);
        for(auto&e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ret = traverse(0,-1,graph);
        return count;
    }
};