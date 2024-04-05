#include <vector>
using namespace std;
class Solution {
public:
    int minimumLevels(vector<int>& possible) {
//         greedy
        
        vector<int> enemy_score(possible.size()+1,0);
        for(int i=possible.size()-1; i >=0; i--){
            enemy_score[i] = possible[i] == 0 ? enemy_score[i+1] - 1 : enemy_score[i+1] + 1;
        }
        
        int current_score = 0;
        for(int i=0; i<possible.size()-1; i++){
            current_score = possible[i] == 0 ? current_score -1 : current_score + 1;
            if(current_score > enemy_score[i+1]) return i+1;
        }
        return -1;
    }
};