#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        // 2D kadanes (have to learn)
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int> prefix_col(m,0);
            for(int j=i; j<n; j++){

                // count column
                for(int k=0; k<m; k++){
                    prefix_col[k] += matrix[k][j];
                }

                // 1D kadane
                int cur_sum = 0;
                set<int> cur_set;
                cur_set.insert(0);
                for(int k=0; k<m; k++){
                    cur_sum += prefix_col[k];
                    set<int>::iterator sit = cur_set.lower_bound(cur_sum - target);
                    if(sit != cur_set.end()) ans = max(ans,cur_sum - *sit);
                    cur_set.insert(cur_sum);
                }
            }
        }
        return ans;
    }
};