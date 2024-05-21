#include <set>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        bool v = false, c = false;
        set<int> vowel_set = {'A','E','I','O','U','a','e','i','o','u'};
        if(word.size() < 3) return false;
        
        for(auto& ch: word){
            if(vowel_set.count(ch)) v = true;
            else if((ch - 'a' >= 0 && ch-'a' < 26 ) || (ch - 'A' >= 0 && ch - 'A' < 26)) c = true;
            else if(ch - '0' >= 0 && ch-'0' <= 9) continue;
            else return false;
        }
        return (v & c) ? true : false;
    }
};