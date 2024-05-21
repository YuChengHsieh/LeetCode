#include <vector>
using namespace std;
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int black_cnt = 0;
        black_cnt += grid[0][0] == 'B';
        black_cnt += grid[0][1] == 'B';
        black_cnt += grid[1][0] == 'B';
        black_cnt += grid[1][1] == 'B';
        if(black_cnt != 2) return true;
        
        black_cnt = 0;
        black_cnt += grid[0][1] == 'B';
        black_cnt += grid[0][2] == 'B';
        black_cnt += grid[1][1] == 'B';
        black_cnt += grid[1][2] == 'B';
        if(black_cnt != 2) return true;
        
        black_cnt = 0;
        black_cnt += grid[1][0] == 'B';
        black_cnt += grid[1][1] == 'B';
        black_cnt += grid[2][0] == 'B';
        black_cnt += grid[2][1] == 'B';
        if(black_cnt != 2) return true;
        
        black_cnt = 0;
        black_cnt += grid[1][1] == 'B';
        black_cnt += grid[1][2] == 'B';
        black_cnt += grid[2][1] == 'B';
        black_cnt += grid[2][2] == 'B';
        if(black_cnt != 2) return true;
        
        return false;
    }
};