#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int cur_row = 0, cur_col = 0;
        for(auto& s: commands){
            if(s == "RIGHT") cur_col ++;
            else if(s == "UP") cur_row --;
            else if(s == "LEFT") cur_col --;
            else if(s == "DOWN") cur_row ++;
        }

        return cur_row*n + cur_col;
    }
};