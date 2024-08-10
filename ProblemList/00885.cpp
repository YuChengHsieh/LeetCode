#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<int> dir_row = {0,1,0,-1};
        vector<int> dir_col = {1,0,-1,0};
        int dir_cnt = 0, span_cnt = 1, cur_row = rStart, cur_col = cStart;
        ans.push_back({cur_row,cur_col});
        while(ans.size() < rows*cols){
            for(int i=0; i<span_cnt; i++){
                cur_row += dir_row[dir_cnt];
                cur_col += dir_col[dir_cnt];
                if(cur_row < rows && cur_row >=0 && cur_col < cols && cur_col >= 0) ans.push_back({cur_row,cur_col});
            }
            if(dir_cnt%2 == 1) span_cnt ++;
            dir_cnt = (dir_cnt+1)%4;
        }

        return ans;
    }
};