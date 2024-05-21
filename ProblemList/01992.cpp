#include <vector>
using namespace std;
class Solution {
private:
    int bottom_row, bottom_col;
    void dfs(int row, int col, vector<vector<int>>& land){
        if(row >= land.size() || col >= land[0].size() || land[row][col] == 0){
            bottom_row = max(bottom_row,row-1);
            bottom_col = max(bottom_col,col-1);
            return;
        }
        land[row][col] = 0;
        dfs(row+1,col,land);
        dfs(row,col+1,land);
        return;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[0].size(); j++){
                if(land[i][j] == 1){
                    bottom_row = 0;
                    bottom_col = 0;
                    vector<int> tmp = {i,j};
                    dfs(i,j,land);
                    tmp.push_back(bottom_row);
                    tmp.push_back(bottom_col);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};