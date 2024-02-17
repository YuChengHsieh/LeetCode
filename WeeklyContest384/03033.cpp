#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int> max_col(matrix[0].size(),-2);
        for(int c=0; c<matrix[0].size(); c++){
            for(int r=0; r<matrix.size(); r++){
                if(matrix[r][c] > max_col[c]) max_col[c] = matrix[r][c];
            }
        }
        
        for(int c=0; c<matrix[0].size(); c++){
            for(int r=0; r<matrix.size(); r++){
                if(matrix[r][c] == -1 ) matrix[r][c] = max_col[c];
            }
        }
        
        return matrix;
    }
};