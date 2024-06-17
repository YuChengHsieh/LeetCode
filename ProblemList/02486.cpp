#include <string>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_idx = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == t[t_idx]) t_idx++;
        }
        return t.size()-t_idx;
    }
};