#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    bool check(vector<int>& row_sum, vector<int>& col_sum, int dig_sum1, int dig_sum2, map<int,int> nums){
        if(dig_sum1 != dig_sum2 || nums.size() != 9 || nums.begin() -> first < 1 || nums.rbegin() -> first > 9) return false;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(row_sum[i] != col_sum[j] || row_sum[i] != dig_sum1) return false;
            }
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m < 3 || n < 3) return 0;
        int ans = 0;

        for(int i=0; i<m-2; i++){
            vector<int> row_sum(3,0), col_sum(3,0);
            map<int,int> nums;
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    row_sum[j] += grid[i+j][k];
                    col_sum[k] += grid[i+j][k];
                    nums[grid[i+j][k]] ++;
                }
            }

            if(check(row_sum, col_sum, grid[i][0] + grid[i+1][1] + grid[i+2][2], 
                grid[i+2][0] + grid[i+1][1] + grid[i][2], nums)) ans ++;
            for(int j=0; j<n-3; j++){
                int val = 0;
                for(int k=0; k<3; k++){
                    row_sum[k] -= grid[i+k][j];
                    nums[grid[i+k][j]] --;
                    if(nums[grid[i+k][j]] == 0) nums.erase(grid[i+k][j]);
                    row_sum[k] += grid[i+k][j+3];
                    nums[grid[i+k][j+3]]++;
                    val += grid[i+k][j+3];
                }

                for(int k=0; k<2; k++){
                    col_sum[k] = col_sum[k+1];
                }

                col_sum[2] = val;

                if(check(row_sum, col_sum, grid[i][j+1] + grid[i+1][j+2] + grid[i+2][j+3], 
                    grid[i+2][j+1] + grid[i+1][j+2] + grid[i][j+3], nums)) ans ++;
            }
        }

        return ans;
    }
};