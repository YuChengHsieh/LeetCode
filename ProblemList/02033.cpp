#include <vector>
using namespace std;
class Solution {
private:
    int convert(int val, const vector<int>& mat, int x){
        int cnt = 0;
        for(auto& num: mat){
            if((val-num)%x != 0) return -1;
            cnt += abs((val-num)/x);
        }
        return cnt;
    }
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> mat;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                mat.push_back(grid[i][j]);
            }
        }
        sort(mat.begin(), mat.end());
        int n = mat.size();
        return n == 1 ? convert(mat[n/2],mat,x) : min(convert(mat[n/2],mat,x),convert(mat[n/2-1],mat,x));
    }
};