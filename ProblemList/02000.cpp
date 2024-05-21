#include <string>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        bool done = false;
        for(auto c: word){
            ans += c;
            if(c == ch && !done){
                done = true;
                reverse(ans.begin(),ans.end());
            } 
        }
        return ans;
    }
};