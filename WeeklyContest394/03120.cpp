#include <string>
#include <set>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        set<char> s;
        for(int i=0; i<word.size(); i++){
            if(s.count(word[i])) continue;
            if(s.count(word[i]+32) || s.count(word[i]-32)) ans += 1;
            s.insert(word[i]);
        }
        return ans;
    }
};