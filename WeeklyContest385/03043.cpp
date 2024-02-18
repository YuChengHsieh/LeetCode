#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
private:
    struct TrieNode{
        char num;
        unordered_map<int,TrieNode*> map;
        TrieNode(char c): num(c) {};
    };
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode(' ');
        for(auto& ch: arr1){
            stringstream ss;
            ss << ch;
            string str = ss.str();
            TrieNode* cur = root;
            for(auto& ch: str){
                if(!cur -> map.count(ch)){
                    TrieNode* tmp = new TrieNode(ch);
                    cur -> map[ch] = tmp;
                }
                cur = cur -> map[ch];
            }
        }
        
        int ans = 0;
        for(auto& ch: arr2){
            stringstream ss;
            ss << ch;
            string str = ss.str();
            TrieNode* cur = root;
            int cnt = 0;
            for(auto& ch: str){
                if(!cur -> map.count(ch)) break;
                cnt += 1;
                cur = cur -> map[ch];
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};