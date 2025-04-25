#include <vector>
using namespace std;
class Solution {
private:
    int cnt = 0;
    int group_cnt = 0;
    void dfs1(int r, int c, vector<vector<bool>>& visited1, vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r == grid.size() || c == grid[0].size() 
        || grid[r][c] == 0 || visited1[r][c]) return;
        cnt ++;
        visited1[r][c] = true;
        dfs1(r+1,c,visited1,grid);
        dfs1(r,c+1,visited1,grid);
        dfs1(r-1,c,visited1,grid);
        dfs1(r,c-1,visited1,grid);
        return;
    }
    void dfs2(int r, int c, vector<vector<bool>>& visited2, vector<vector<pair<int,int>>>& counts ,vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r == grid.size() || c == grid[0].size() 
        || grid[r][c] == 0 || visited2[r][c]) return;
        
        counts[r][c].first = cnt;
        counts[r][c].second = group_cnt;
        visited2[r][c] = true;
        dfs2(r+1,c,visited2,counts,grid);
        dfs2(r,c+1,visited2,counts,grid);
        dfs2(r-1,c,visited2,counts,grid);
        dfs2(r,c-1,visited2,counts,grid);
        return;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited1(m, vector<bool>(n,false));
        vector<vector<bool>> visited2(m, vector<bool>(n,false));
        vector<vector<pair<int,int>>> counts(m, vector<pair<int,int>>(n,{0,0}));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited1[i][j]){
                    dfs1(i,j,visited1,grid);
                    dfs2(i,j,visited2,counts,grid);
                    cnt = 0;
                    group_cnt ++;
                }
            }
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout << counts[i][j].first << ' ';
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        bool inside = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]){
                    inside = true;
                    int cur = 0;
                    vector<bool> visited_groups(group_cnt,false);

                    if(i-1 >= 0 && grid[i-1][j] && !visited_groups[counts[i-1][j].second]){
                        visited_groups[counts[i-1][j].second] = true;
                        cur += counts[i-1][j].first;
                    }

                    if(i+1 < m && grid[i+1][j] && !visited_groups[counts[i+1][j].second]){
                        visited_groups[counts[i+1][j].second] = true;
                        cur += counts[i+1][j].first;
                    }

                    if(j-1 >= 0 && grid[i][j-1] && !visited_groups[counts[i][j-1].second]){
                        visited_groups[counts[i][j-1].second] = true;
                        cur += counts[i][j-1].first;
                    }

                    if(j+1 < n && grid[i][j+1] && !visited_groups[counts[i][j+1].second]){
                        visited_groups[counts[i][j+1].second] = true;
                        cur += counts[i][j+1].first;
                    }
                    
                    ans = max(ans,cur);
                }
            }
        }
        return (ans == 0 && !inside) ? m*n : ans+1;
    }
};