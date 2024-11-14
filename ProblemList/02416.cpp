#include <vector>
#include <map>
#include <string>
using namespace std;
struct Trie{
    map<char,Trie*> next;
    int val;
    Trie() : val(0) {}
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for(auto& w: words){
            Trie* cur = root;
            for(auto& ch: w){
                if(!cur -> next.count(ch)){
                    Trie* newn = new Trie();
                    cur -> next[ch] = newn;
                }
                cur = cur -> next[ch];
                cur -> val += 1;
            }
        }

        vector<int> ans;
        for(auto& w: words){
            int cnt = 0;
            Trie* cur = root;
            for(auto& ch: w){
                cur = cur -> next[ch];
                cnt += cur -> val;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};