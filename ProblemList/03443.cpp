#include <vector>
using namespace std;
class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> dir_cnts(4,0);
        int row = 0, col = 0, ans = 0;
        for(auto& ch: s){
            if(ch == 'N'){
                col ++;
                dir_cnts[0] ++;
            }else if(ch == 'S'){
                col --;
                dir_cnts[1] --;
            }else if(ch == 'E'){
                row ++;
                dir_cnts[2] ++;
            }else if(ch == 'W'){
                row --;
                dir_cnts[3] --;
            }
            
            int min_row, min_col;
            if(col == 0) min_col = dir_cnts[0] > dir_cnts[1] ? dir_cnts[0] : dir_cnts[1];
            else if(col > 0) min_col = dir_cnts[1];
            else min_col = dir_cnts[0];

            if(row == 0) min_row = dir_cnts[2] > dir_cnts[3] ? dir_cnts[2] : dir_cnts[3];
            else if(row > 0) min_row = dir_cnts[3];
            else min_row = dir_cnts[2];

            ans = max(ans, abs(row) + abs(col) + 
                    + 2*min(abs(min_row) +  abs(min_col) ,k));

        }
        return ans;
    }
};