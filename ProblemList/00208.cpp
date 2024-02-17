#include <unordered_map>
#include <string>
using namespace std;
struct TrieNode{
    char query;
    bool end;
    unordered_map<char,TrieNode*> map;
    TrieNode(char ch): query(ch), end(false) {};
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(' ');    
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto &ch: word){
            if(!cur->map.count(ch)){
                TrieNode* tmp = new TrieNode(ch);
                cur -> map[ch] = tmp;
            }
            cur = cur -> map[ch];
        }
        cur -> end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto &ch: word){
            if(!cur -> map.count(ch)) return false;
            cur = cur -> map[ch];
        }
        return cur -> end ? true : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto &ch: prefix){
            if(!cur -> map.count(ch)) return false;
            cur = cur -> map[ch];
        }
        return true;
    }
};
