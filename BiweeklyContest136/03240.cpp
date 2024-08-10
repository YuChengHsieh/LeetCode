#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int cnts = 0, m = grid.size(), n = grid[0].size();
        int right = n-1, down = m-1, ans = 0;         

        for(int i=0; i<m/2; i++){
            for(int j=0; j<n/2; j++){
                int zero_cnt = 0;
                if(grid[i][j] == 0) zero_cnt ++;
                if(grid[i][right-j] == 0) zero_cnt ++;
                if(grid[down-i][j] == 0) zero_cnt ++;
                if(grid[down-i][right-j] == 0) zero_cnt ++;
                ans += min(4-zero_cnt,zero_cnt);
            }
        }
        
        int diff = 0, p0 = 0, p1 = 0;
        if(m%2 == 1){
            for(int j=0; j<n/2; j++){
                if(grid[m/2][j] != grid[m/2][right-j]) diff++;
                else if(grid[m/2][j] == 1) p1 ++;
                else p0 ++;
            }
        }

        if(n%2 == 1){
            for(int i=0; i<m/2; i++){
                if(grid[i][n/2] != grid[down-i][n/2]) diff ++;    
                else if(grid[i][n/2] == 1) p1 ++;
                else p0 ++;
            }
        }

        if(m%2 == 1 && n%2 == 1){
            if(grid[m/2][n/2] == 1) ans ++;
        }

        int ans1 = INT_MAX;
        if(diff%2 == p1%2) ans1 = diff;
        else{
            if(diff%2 == 0 && diff == 0) ans1 = 2;
            else ans1 = diff;
        }
        return ans+ans1;
    }
};