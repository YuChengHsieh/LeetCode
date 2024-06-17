#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int ans = 0;
    void rec(int idx, int scores, vector<int>& letter_cnts, vector<string>& words,  vector<int>& score){
        if(idx == words.size()){
            ans = max(ans, scores);
            return;
        }
         
        vector<int> orig_letter_cnts = letter_cnts;
        int cur_score = 0;
        bool success = true;
        for(auto& ch: words[idx]){
            letter_cnts[ch-'a'] -= 1;
            cur_score += score[ch-'a'];
            if(letter_cnts[ch-'a'] < 0){
                success = false;
                break;
            }
        }
        if(success) rec(idx+1,scores+cur_score,letter_cnts,words,score);
        rec(idx+1,scores,orig_letter_cnts,words,score);
        return;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letter_cnts(26,0);
        for(auto& l: letters){
            letter_cnts[l-'a'] += 1;
        }
        rec(0,0,letter_cnts,words,score);
        return ans;
    }
};