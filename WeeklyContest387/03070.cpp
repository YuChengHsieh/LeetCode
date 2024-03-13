#include <vector>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prefix(m,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                prefix[j] += grid[j][i];
            }
            
            // for(auto& num: prefix) cout << num << ' ';
            // cout << endl;
            
            int tmp_cnt = 0;
            for(int j=0; j<m; j++){
                tmp_cnt += prefix[j];
                if(tmp_cnt <= k) cnt += 1;
            }
        }
        return cnt;
    }
};