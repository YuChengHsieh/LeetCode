#include <vector>
using namespace std;
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rest(3,0);
        vector<int> Y(3,0);
        int total_rest = 0, total_Y = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i <= n/2 && (j == i || j == n-i-1)){
                    Y[grid[i][j]] += 1;
                    total_Y ++;
                } 
                else if(i > n/2 && j == n/2){
                    Y[grid[i][j]] += 1;
                    total_Y ++;
                } 
                else{
                    rest[grid[i][j]] += 1;
                    total_rest ++;
                } 
            }
        }
        
        int rest_cnt = 0, rest_num = 0, second_rest_cnt = 0, second_rest_num = 0, Y_cnt = 0, Y_num = 0, second_Y_cnt = 0, second_Y_num = 0;
        
        for(int i=0; i<3; i++){
            if(rest[i] > rest_cnt){
                second_rest_cnt = rest_cnt;
                second_rest_num = rest_num;
                rest_cnt = rest[i];
                rest_num = i;
            }else if(rest[i] > second_rest_cnt){
                second_rest_cnt = rest[i];
                second_rest_num = i;
            }
        }
        
        for(int i=0; i<3; i++){
            if(Y[i] > Y_cnt){
                second_Y_cnt = Y_cnt;
                second_Y_num = Y_num;
                Y_cnt = Y[i];
                Y_num = i;
            }else if(Y[i] > second_Y_cnt){
                second_Y_cnt = Y[i];
                second_Y_num = i;
            }
        }
        
        if(Y_num == rest_num){
            return min(total_rest-second_rest_cnt + total_Y - Y_cnt, total_rest-rest_cnt + total_Y - second_Y_cnt);
        }else return total_rest-rest_cnt + total_Y - Y_cnt;
    }
};