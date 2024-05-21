#include<vector>
using namespace std;
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if(visited[row][col]) return;
        visited[row][col] = true;
        bool ans = false;
        if(row-1 >= 0 && heights[row][col] <= heights[row-1][col]) dfs(row-1,col,heights,visited); 
        if(col-1 >= 0 && heights[row][col] <= heights[row][col-1]) dfs(row,col-1,heights,visited);
        if(row+1 < heights.size() && heights[row][col] <= heights[row+1][col]) dfs(row+1,col,heights,visited);
        if(col+1 < heights[0].size() && heights[row][col] <= heights[row][col+1]) dfs(row,col+1,heights,visited);
        return;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> Pacafic(m, vector<bool>(n, false));
        vector<vector<bool>> Atlantic(m, vector<bool>(n, false));
        vector<vector<int>> results;


        for(int i=0; i<m; i++){
            dfs(i,0,heights,Pacafic);
            dfs(i,n-1,heights,Atlantic);
        }

        for(int i=0; i<n; i++){
            dfs(0,i,heights,Pacafic);
            dfs(m-1,i,heights,Atlantic);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(Pacafic[i][j] && Atlantic[i][j]) results.push_back({i,j});
            }
        }

        return results;
    }
};