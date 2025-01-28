#include <vector>
#include <string>
using namespace std;
struct Trie{
    vector<Trie*> next;
    int idx;
    Trie(): next(26,nullptr), idx(INT_MAX) {}
};

class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        Trie* head = new Trie();
        Trie* cur = head;
        int cnt = 1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                cur = head;
                cnt ++;
                continue;
            } 
            if(cur -> next[s[i]-'a'] == nullptr){
                Trie* newn = new Trie();
                cur -> next[s[i]-'a'] = newn;
            }
            cur = cur -> next[s[i]-'a'];
            cur -> idx = min(cur -> idx, cnt);
        }

        cur = head;
        for(auto& ch: searchWord){
            if(cur -> next[ch-'a'] == nullptr) return -1;
            cur = cur -> next[ch-'a'];
        }
        return cur -> idx == INT_MAX ? -1 : cur -> idx;
    }
};