#include <vector>
#include <set>
using namespace std;
class Solution {
private:
    int cur_val = 0;
    void dfs(int row, int col, vector<vector<int>>& rows, vector<vector<int>>& cols, set<pair<int,int>>& visited){
        cur_val += 1;
        visited.insert({row,col});
        for(auto& nextc: rows[row]){
            if(!visited.count({row,nextc})) dfs(row,nextc,rows,cols,visited);
        }
        for(auto& nextr: cols[col]){
            if(!visited.count({nextr,col})) dfs(nextr,col,rows,cols,visited);
        }
        return;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> rows(10001);
        vector<vector<int>> cols(10001);
        set<pair<int,int>> visited; 

        for(auto& s: stones){
            rows[s[0]].push_back(s[1]);
            cols[s[1]].push_back(s[0]);
        }

        int ans = 0;
        for(auto& s: stones){
            if(!visited.count({s[0],s[1]})){
                dfs(s[0],s[1],rows,cols,visited);
                ans += cur_val-1;
                cur_val = 0;
            }
        }
        return ans;
    }
};