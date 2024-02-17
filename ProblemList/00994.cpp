#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size(), cols = grid[0].size();
        int oranges = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1) oranges += 1;
                else if(grid[i][j] == 2){
                    oranges += 1;
                    q.push(make_pair(i,j));
                } 
            }
        }

        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [row,col] = q.front();
                q.pop();
                oranges -= 1; 
                if(oranges == 0) return steps;
                if(row-1 >= 0 && grid[row-1][col] == 1){
                    grid[row-1][col] = 2;
                    q.push(make_pair(row-1,col));
                }
                if(row+1 < rows && grid[row+1][col] == 1){
                    grid[row+1][col] = 2;
                    q.push(make_pair(row+1,col));
                }
                if(col-1 >= 0 && grid[row][col-1] == 1){
                    grid[row][col-1] = 2;
                    q.push(make_pair(row,col-1));
                }
                if(col+1 < cols && grid[row][col+1] == 1){
                    grid[row][col+1] = 2;
                    q.push(make_pair(row,col+1));
                }
            }
            steps += 1;
        }
        return oranges == 0 ? 0 : -1;
    }
};