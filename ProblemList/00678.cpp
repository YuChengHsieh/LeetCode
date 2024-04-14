#include <string>
#include <map>
using namespace std;
// using memorization
class Solution {
private: 
    bool rec(int idx, int left_p, string& s, map<pair<int,int>,bool>& mem){
        if(idx == s.size()) return left_p == 0 ? true : false;
        if(left_p < 0) return false;
        if(mem.count({idx, left_p})) return mem[{idx, left_p}];
        
        bool ans = false;
        if(s[idx] == '(') ans |= rec(idx+1,left_p+1,s,mem);
        else if(s[idx] == ')') ans |= rec(idx+1,left_p-1,s,mem);
        else{
            ans |= rec(idx+1,left_p+1,s,mem);
            ans |= rec(idx+1,left_p-1,s,mem);
            ans |= rec(idx+1,left_p,s,mem);
        }
        return mem[{idx, left_p}] = ans;
    }
public:
    bool checkValidString(string s) {
        map<pair<int,int>,bool> mem;
        return rec(0,0,s,mem);
    }
};