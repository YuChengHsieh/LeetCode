#include <string>
using namespace std;
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx2 = 0;
        for(auto& ch: str1){
            if(ch == str2[idx2] || (ch == 'z' ? str2[idx2] == 'a' : ch+1 == str2[idx2])) idx2 ++;
            if(idx2 == str2.size()) return true;
        }
        return false;
    }
};