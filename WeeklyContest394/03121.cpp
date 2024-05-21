#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        set<char> s;
        vector<bool> del(26,false);
        for(int i=0; i<word.size(); i++){
            if(word[i]-'A' < 26){
                if(!s.count(word[i]) && s.count(word[i]+32)){
                    ans += 1;
                    del[word[i]+32-'a'] = true;
                } 
                s.insert(word[i]);
            }else{
                if(s.count(word[i]) && s.count(word[i]-32)){
                    if(del[word[i]-'a']) ans -= 1;
                    del[word[i]-'a'] = false;
                }
                s.insert(word[i]);
            }
        }
        return ans;
    }
};