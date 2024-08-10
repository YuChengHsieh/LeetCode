#include <vector>
using namespace std;
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnts(n, vector<int>(11,0));
        for(auto& p: pick){
            cnts[p[0]][p[1]] ++;
        }

        int ans  = 0; 
        for(int i=0; i<n; i++){
            for(int j=0; j<11; j++){
                if(cnts[i][j] > i){
                    ans ++;
                    break;
                } 
            }
        }

        return ans;
    }
};