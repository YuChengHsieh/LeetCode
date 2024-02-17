#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a_map(26,0), b_map(26,0);
        
        for(auto const &ch: ransomNote){
            a_map[ch-'a'] += 1;
        }
        for(auto const &ch: magazine){
            b_map[ch-'a'] += 1;
        }

        for(int i=0; i<26; i++){
            if(a_map[i] > b_map[i]) return false;
        }

        return true;
    }
};