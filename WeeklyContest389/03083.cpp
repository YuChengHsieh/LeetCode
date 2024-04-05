#include <string>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool isSubstringPresent(string s) {
        if(s.size() == 1) return false;
        map<char,set<char>> ch;
        ch[s[0]].insert(s[1]);
        for(int i=1; i<s.size()-1; i++){
            if(ch[s[i]].count(s[i-1]) || ch[s[i]].count(s[i+1])) return true;
            ch[s[i]].insert(s[i-1]);
            ch[s[i]].insert(s[i+1]);
        }
        if(ch[s[s.size()-1]].count(s[s.size()-2])) return true;
        return false;
    }
};