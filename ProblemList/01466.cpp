#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int ans = 0;
    unordered_set<int> visited;
    
    void dfs(int cur, vector<vector<pair<int,int>>> &map){
        if(visited.count(cur)) return;
        visited.insert(cur);
        for(auto &next: map[cur]){
            if(visited.count(next.first)) continue;
            ans += next.second;
            dfs(next.first,map);
        }
        return;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int size = connections.size()+1;
        vector<vector<pair<int,int>>> map(size,vector<pair<int,int>>());
        for(auto &connection: connections){
            map[connection[0]].push_back(make_pair(connection[1],1));
            map[connection[1]].push_back(make_pair(connection[0],0));
        }
        dfs(0,map);
        return ans;
    }
};