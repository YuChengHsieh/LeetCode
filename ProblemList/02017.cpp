#include <vector>
using namespace std;

// prefix
class Solution {
private:
    void cal_prefix(vector<long long>& suffix_up, vector<long long>& prefix_down, vector<vector<int>>& grid){
        int n = grid[0].size();
        suffix_up[n-1] = grid[0][n-1];
        prefix_down[0] = grid[1][0];
        for(int i=1; i<n; i++){
            prefix_down[i] = prefix_down[i-1] + grid[1][i];
        }

        
        for(int i=n-2; i>=0; i--){
            suffix_up[i] = suffix_up[i+1] + grid[0][i];
        }
        
    }
    long long cal_max(vector<long long>& suffix_up, vector<long long>& prefix_down, vector<vector<int>>& grid){
        int c = -1;
        for(int i=0; i<suffix_up.size(); i++){
            if(prefix_down[i] >= suffix_up[i]){
                c = i;
                break;
            }
        }
        if(c == -1) c = suffix_up.size()-1;
        long long ans1 = max(prefix_down[c]-grid[1][c],suffix_up[c]-grid[0][c]);
        long long ans2 = c-1 >= 0 ? max(prefix_down[c-1]-grid[1][c-1],suffix_up[c-1]-grid[0][c-1]) : INT_MAX;
        return min(ans1, ans2);
    }
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> suffix_up(n,0), prefix_down(n,0);
        cal_prefix(suffix_up,prefix_down,grid);
        return cal_max(suffix_up,prefix_down,grid);
    }
};


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long up_sum = 0, down_sum = 0;
        for(int i=0; i<n; i++){
            up_sum += grid[0][i];
        }

        long long ans = LONG_LONG_MAX;
        for(int i=0; i<n; i++){
            up_sum -= grid[0][i];
            ans = min(ans, max(up_sum,down_sum));
            down_sum += grid[1][i];
        }
        return ans;
    }
};