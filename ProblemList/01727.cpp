#include <vector>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int> arr;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            
            if(i > 0){
                for(int j=0; j<n; j++){
                    if(matrix[i][j] == 1) matrix[i][j] += matrix[i-1][j];
                }
            }

            vector<int> row = matrix[i];
            sort(row.begin(), row.end());
            for(int i=0; i<n; i++){
                ans = max(ans, row[i]*(n-i));
            }
        }
        return ans;
    }
};