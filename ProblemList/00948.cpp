#include<vector>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int start = 0, end = tokens.size()-1;
        int cur_power = power, cur_score = 0, max_score = 0;
        while(start <= end){
            if(cur_power - tokens[start] >= 0){
                cur_power -= tokens[start];
                cur_score += 1;
                max_score = max(max_score, cur_score);
                start ++;
            }else if(cur_score > 0){
                cur_power += tokens[end];
                cur_score -= 1;
                end --;
            }else break;
        }
        return max_score;
    }
};