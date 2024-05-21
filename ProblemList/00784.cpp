#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<string> ans;
    void rec(int idx, string s){
        if(idx == s.size()){
            ans.push_back(s);
            return;
        }
        rec(idx+1,s);
        if(!isdigit(s[idx])){
            if(s[idx] >= 'a' && s[idx] <= 'z'){
                s[idx] -= 32;
                rec(idx+1,s);
            }else{
                s[idx] += 32;
                rec(idx+1,s);
            }
        }
        return;
    }
public:
    vector<string> letterCasePermutation(string s) {
        rec(0,s);
        return ans;
    }
};