#include <string> 
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char last = ' '; 
        int con = 1;
        for(auto& ch: s){
            if(ch != last){
                ans += ch;
                con = 1;
            }else if(con < 2){
                ans += ch;
                con ++;
            }
            last = ch;
        }
        return ans;
    }
};