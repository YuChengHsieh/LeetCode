#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int live_cnt;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                live_cnt = 0;
                if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1]) live_cnt += 1;
                if(i-1 >= 0 && board[i-1][j]) live_cnt += 1; 
                if(i-1 >= 0 && j+1 <n && board[i-1][j+1]) live_cnt += 1; 
                if(j-1 >= 0 && board[i][j-1]) live_cnt += 1; 
                if(j+1 < n  && board[i][j+1]) live_cnt += 1; 
                if(i+1 < m  && j-1 >= 0 && board[i+1][j-1]) live_cnt += 1; 
                if(i+1 < m  && board[i+1][j]) live_cnt += 1; 
                if(i+1 < m  && j+1 < n && board[i+1][j+1]) live_cnt += 1; 
                
                if( (board[i][j] && live_cnt >= 2 && live_cnt <= 3) || (!board[i][j] && live_cnt == 3))  ans[i][j] = 1;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] = ans[i][j];
            }
        }
    }
};