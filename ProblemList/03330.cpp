#include <string>
using namespace std;
class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char prev = ' ';
        for(auto& ch: word){
            if(ch == prev) ans ++;
            prev = ch;
        }
        return ans;
    }
};