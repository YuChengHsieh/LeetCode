#include <map>
#include <string>
#include <vector>
using namespace std;
struct TrieNode{
    char ch;
    bool end;
    map<char,TrieNode*> trie_map;
    TrieNode(char c): ch(c), end(false) {};
};

class Solution {
private:
    void traverse_trie(TrieNode* cur, string ret_str, vector<string> &ans){
        if(cur -> end) ans.push_back(ret_str);
        if(ans.size() >= 3) return;
        
        for(auto item: cur -> trie_map){
            ret_str += item.first;
            traverse_trie(item.second, ret_str, ans);
            if(ans.size() >= 3) break;
            ret_str.erase(ret_str.size()-1);
        }
        return;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode(' ');
        TrieNode* cur;
        for(auto &p: products){
            cur = root;
            for(auto &ch: p){
                if(!cur -> trie_map.count(ch)) cur -> trie_map[ch] = new TrieNode(ch);
                cur = cur -> trie_map[ch]; 
            }
            cur -> end = true;
        }

        vector<vector<string>> ans(searchWord.size(), vector<string>());
        cur = root;
        string str = "";
        for(int i=0; i<searchWord.size(); i++){
            char ch = searchWord[i];
            if(!cur -> trie_map.count(ch)) break;
            vector<string> tmp;
            str += ch;
            traverse_trie(cur-> trie_map[ch],str,tmp);
            ans[i] = tmp;
            cur = cur -> trie_map[ch];
        }
        return ans;
    }
};