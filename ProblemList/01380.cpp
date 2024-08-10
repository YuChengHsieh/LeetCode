#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> min_rows(m,INT_MAX), max_cols(n,INT_MIN);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                max_cols[j] = max(max_cols[j],matrix[i][j]);
                min_rows[i] = min(min_rows[i],matrix[i][j]);
            }
        }

        set<int> min_set = set(min_rows.begin(),min_rows.end());
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(min_set.count(max_cols[i])) ans.push_back(max_cols[i]);
        }
        return ans;
    }
};