#include <unordered_set>
using namespace std;
class Solution {
private:
    unordered_set<int> visited;
    void dfs(int num, vector<unordered_set<int>>& map){
        if(visited.count(num)) return;
        visited.insert(num);
        for(auto &nextn: map[num]){
            if(!visited.count(nextn)) dfs(nextn, map);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<unordered_set<int>> map(size, unordered_set<int>());
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                if(isConnected[i][j] == 1){
                    map[i].insert(j);
                    map[j].insert(i);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<size; i++){
            if(!visited.count(i)){
                dfs(i,map);
                ans += 1;
            }
        }
        return ans;
    }
};