#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    struct TrieNode{
        unordered_map<int,TrieNode*> map;
        int count;
        TrieNode(): count(0) {};
    };
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        long long ans = 0;
        for(auto& word: words){
            TrieNode* cur = root;
            for(int i=0, n=word.size(); i<n; i++){
                if(!cur -> map.count(word[i]*128 + word[n-i-1])){
                    TrieNode* tmp = new TrieNode();
                    cur -> map[word[i]*128 + word[n-i-1]] = tmp;
                }
                cur = cur -> map[word[i]*128 + word[n-i-1]];
                ans += cur -> count;   
            }
            cur -> count += 1;
        }
        return ans;
    }
};