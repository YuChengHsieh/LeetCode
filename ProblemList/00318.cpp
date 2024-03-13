#include <vector>
#include <string>
using namespace std;

// use vector catch
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<vector<bool>,int>> cnt;
        for(auto& word: words){
            vector<bool> vec(26,false);
            for(auto ch: word) vec[ch-'a'] = true;
            cnt.push_back({vec,word.size()});
        }

        int max_size = 0;
        for(int i=0; i<cnt.size(); i++){
            for(int j=i+1; j<cnt.size(); j++){
                for(int k=0; k<26; k++){
                    if(cnt[i].first[k] && cnt[j].first[k]) break;
                    if(k == 25) max_size = max(max_size,cnt[i].second*cnt[j].second);
                } 
            }
        }
        return max_size;
    }
};

// use bit catch
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> cnt;
        for(auto& word: words){
            int val = 0;
            for(auto ch: word) val |= 1 << (ch-'a');
            cnt.push_back(val);
        }

        int max_size = 0;
        for(int i=0; i<cnt.size(); i++){
            for(int j=i+1; j<cnt.size(); j++){
                if( (cnt[i] & cnt[j])  == 0) max_size = max(max_size,(int)words[i].size()*(int)words[j].size());
            }
        }
        return max_size;
    }
};