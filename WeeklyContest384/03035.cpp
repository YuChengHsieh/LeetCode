#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> char_dict(26,0);
        for(auto &word: words){
            for(auto &ch: word){
                char_dict[ch-'a'] += 1;
            }
        }

        int pairs = 0;
        for(auto const &counts: char_dict){
            pairs += counts/2;
        }

        sort(words.begin(), words.end(), [](string a, string b){
            return a.size() < b.size();
        });

        int ans = 0;
        for(auto const word: words){
            if(pairs >= word.size()/2){
                pairs -=  word.size()/2;
                ans += 1;
            }else break; 
        }
        return ans;
    }
};