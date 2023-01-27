// trie structure
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
struct TrieNode {
    bool end = false;
    unordered_map<char,TrieNode*> map;
    TrieNode(){}
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary(){
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto &i: word){
            if(!cur->map.count(i)){
                TrieNode* tmp = new TrieNode();
                cur->map[i] = tmp;
            }
            cur = cur->map[i];
        }
        cur->end = true;
    }
    
    bool trie_search(TrieNode* cur,int idx, string word){
        bool ret_val = false;
        if(idx == word.size() and cur->end == true) return true;
        if(word[idx] == '.'){
            for(auto &j:cur->map){
                ret_val = trie_search(j.second,idx+1,word);
                if(ret_val == true) break;
            }
        }
        else if(cur->map.count(word[idx]))
            ret_val = trie_search(cur->map[word[idx]],idx+1,word);
        else return false;
        return ret_val;
    }

    bool search(string word) {
        return trie_search(root,0,word);
    }
};