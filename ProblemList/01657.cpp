#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> word1_cnt(26,0);
        vector<int> word2_cnt(26,0);
        unordered_map<int,int> cmp1;
        unordered_map<int,int> cmp2;

        for(auto &ch: word1){
            word1_cnt[ch-'a'] += 1;
        }
        for(auto &ch: word2){
            word2_cnt[ch-'a'] += 1;
        }

        for(int i=0; i<26; i++){
            if((word1_cnt[i] == 0 && word2_cnt[i] != 0) || (word1_cnt[i] != 0 && word2_cnt[i] == 0)) return false;
            cmp1[word1_cnt[i]] += 1;
        }
        for(auto &cnt: word2_cnt){
            cmp2[cnt] += 1;
        }
        return cmp1 == cmp2;

    }
};