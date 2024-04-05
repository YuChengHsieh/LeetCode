#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
struct TrieNode{
    unordered_map<char, TrieNode*> char_dict;
    int smallest_length = INT_MAX;
    int smallest_idx = -1;
    TrieNode(){}
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        
        for(int i=0; i<wordsContainer.size(); i++){
            TrieNode* cur = root;
            string word = wordsContainer[i];
            for(int j=word.size()-1; j>=0; j--){
                if(word.size() < cur -> smallest_length){
                    cur -> smallest_length = word.size();
                    cur -> smallest_idx = i;
                }
                if(!cur -> char_dict.count(word[j])){
                    TrieNode* nextn = new TrieNode();
                    cur -> char_dict[word[j]] = nextn;
                }
                cur = cur -> char_dict[word[j]];
            }
            if(word.size() < cur -> smallest_length){
                cur -> smallest_length = word.size();
                cur -> smallest_idx = i;
            }
        }
        
        
        vector<int> ans;
        for(int i=0; i<wordsQuery.size(); i++){
            TrieNode* cur = root;
            string word = wordsQuery[i];
            for(int j=word.size()-1; j>=0; j--){
                if(!cur -> char_dict.count(word[j])) break;
                cur = cur -> char_dict[word[j]];
            }
            // cout << word << ' ' << cur -> smallest_length << ' ' << cur -> smallest_idx << endl;
            ans.push_back(cur -> smallest_idx);
        }
        return ans;   
    }
};