#include <vector>
#include <string>
using namespace std;

// using trie
struct TrieNode{
    vector<TrieNode*> next;
    bool end;
    TrieNode(): next(26,nullptr), end(false) {};
};
class Solution {
private:
    vector<string> ans;
    TrieNode* trieRoot;
    void rec(int idx, TrieNode* curNode, string& curS, string& s){
        if(idx == s.size()){
            if(curNode -> end) ans.push_back(curS);
            return;
        } 

        if(curNode -> end){
            string newS = curS + " ";
            rec(idx,trieRoot,newS,s);
        }

        if(curNode->next[s[idx]-'a']){ 
            curS += s[idx];
            rec(idx+1,curNode->next[s[idx]-'a'],curS,s);
            curS.pop_back();
        }
        return;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trieRoot = new TrieNode();
        for(auto& word: wordDict){
            TrieNode* cur = trieRoot;
            for(auto ch: word){
                if(cur -> next[ch-'a'] == nullptr){
                    TrieNode* newNode = new TrieNode();
                    cur -> next[ch-'a'] = newNode;
                }
                cur = cur -> next[ch-'a'];
            }
            cur -> end = true;
        }
        
        string cur;
        rec(0,trieRoot,cur,s);
        return ans;
    }
};