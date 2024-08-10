#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<bool>>& graph){
        if(row < 0 || col < 0 || row >= graph.size() || col >= graph.size() || graph[row][col]) return;
        graph[row][col] = 1;
        dfs(row-1,col,graph);
        dfs(row,col-1,graph);
        dfs(row+1,col,graph);
        dfs(row,col+1,graph);
        return;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> graph(n*3, vector<bool>(n*3,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '\\'){
                    graph[i*3][j*3] = 1;
                    graph[i*3+1][j*3+1] = 1;
                    graph[i*3+2][j*3+2] = 1;
                }else if(grid[i][j] == '/'){
                    graph[i*3+2][j*3] = 1;
                    graph[i*3+1][j*3+1] = 1;
                    graph[i*3][j*3+2] = 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n*3; i++){
            for(int j=0; j<n*3; j++){
                if(!graph[i][j]){
                    dfs(i,j,graph);
                    ans ++;
                }
            }
        }
        return ans;
        
    }
};