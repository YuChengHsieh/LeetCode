#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {

        // cal frequency and appear idx
        vector<vector<int>> ch_map(26);
        for(int i=0; i<s.size(); i++){
            ch_map[s[i]-'a'].push_back(i);
        }
        
        // get the char with most freq, contain_s get the character that with maximum frequency
        int max_val = 0;
        vector<int> contain_s;
        for(int i=0; i<26; i++){
            if (ch_map[i].size() > max_val){
                max_val = ch_map[i].size();
                contain_s = {i};
            }else if(ch_map[i].size() == max_val) contain_s.push_back(i);
        }
        
        //  sort_ contain the pair: int: last idx of given character, character: character with most appear frequency
        vector<pair<int,char>> sort_;
        for(int i=0; i<contain_s.size(); i++){
            sort_.push_back({ch_map[contain_s[i]][max_val-1], contain_s[i]+'a'});
        }

        // sort the sort_
        sort(sort_.begin(),sort_.end(),[](pair<int,char>& a, pair<int,char>& b){
            return a.first < b.first; 
        });
        
        // get the character from ans
        string ans;
        for(auto& ch: sort_){
            ans += ch.second;
        }
        return ans;
    }
};