#include<vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefix[i][j] = prefix[i][j-1] + matrix[i-1][j-1];
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                prefix[j][i] += prefix[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1];
    }
};
