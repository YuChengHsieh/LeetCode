#include <vector>
#include <string>
using namespace std;

// Trie 
struct TrieNode{
    vector<TrieNode*> next;
    bool end = false;
    TrieNode(): next(26,nullptr) {};
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(),dictionary.end(),[](string& a, string& b){
            return a.size() < b.size();
        });

        TrieNode* root = new TrieNode();
        string ans;
        for(auto& word: dictionary){
            TrieNode* cur = root;
            for(auto& ch: word){
                if(cur -> next[ch-'a'] == nullptr){
                    TrieNode* nextn = new TrieNode();
                    cur -> next[ch-'a'] = nextn;
                }else if(cur -> end) break;
                cur = cur -> next[ch-'a'];
            }
            cur -> end = true;
        }

        int s_idx = 0;
        
        while(s_idx < sentence.size()){
            TrieNode* cur = root;
            string tmp;
            while(s_idx < sentence.size() && sentence[s_idx] != ' '){
                if(cur != nullptr && cur -> end){
                }else{
                    tmp += sentence[s_idx];
                    if(cur != nullptr){
                        cur = cur -> next[sentence[s_idx]-'a'];
                    } 
                }
                s_idx ++;
            }
            s_idx ++;
            ans += tmp+' ';
        }
        ans.pop_back();
        return ans;
    }
};