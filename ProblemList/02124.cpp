#include <string>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for(auto& ch: s){
            if(ch == 'b') b = true;
            else if(b) return false;
        }
        return true;
    }
};