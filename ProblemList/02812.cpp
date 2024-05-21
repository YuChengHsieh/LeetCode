#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    bool dfs(int r, int c, int val, vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid.size() || grid[r][c] < val) return false;
        if(r == grid.size()-1 && c == grid.size()-1) return true;
        grid[r][c] = val-1;
        return dfs(r+1,c,val,grid) | dfs(r-1,c,val,grid) | dfs(r,c+1,val,grid) | dfs(r,c-1,val,grid);
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> ones_cnt;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) ones_cnt.push_back({i,j});
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = -1;
            }
        }

        queue<pair<int,int>> q;
        for(auto& pt: ones_cnt){
            q.push(pt);
            grid[pt.first][pt.second] = 0;
        }

        int fac = 0;
        while(q.size() != 0){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [r,c] = q.front();
                q.pop();
                if(r-1 >= 0 && grid[r-1][c] == -1){
                    q.push({r-1,c});
                    grid[r-1][c] = fac+1;
                }
                if(r+1 < n && grid[r+1][c] == -1){
                    q.push({r+1,c});
                    grid[r+1][c] = fac+1;
                }
                if(c-1 >= 0 && grid[r][c-1] == -1){
                    q.push({r,c-1});
                    grid[r][c-1] = fac+1;
                }
                if(c+1 < n && grid[r][c+1] == -1){
                    q.push({r,c+1});
                    grid[r][c+1] = fac+1;
                }
            }
            fac += 1;
        }

        int start = 0, end = 2*n;
        while(start <= end){
            int mid = start + (end-start)/2;
            vector<vector<int>> tmp_grid = grid;
            if(dfs(0,0,mid,tmp_grid)) start = mid + 1;
            else end = mid - 1;
        }

        return end;
    }
};