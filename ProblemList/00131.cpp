#include <vector>
#include <string>
using namespace std;
// similar to knapsack
class Solution {
private:
    vector<vector<string>> ans;

    bool check(const string& s){
        int sz = s.size();
        for(int i=0; i<sz/2; i++){
            if(s[i] != s[sz-i-1]) return false;
        }
        return true;
    }

    void rec(int idx, vector<string>& vs, string cur_s, string& s){
        if(idx == s.size()){
            if(cur_s == "") ans.push_back(vs);
            return;
        }

        cur_s += s[idx];
        if(check(cur_s)){
            vs.push_back(cur_s);
            rec(idx+1,vs,"",s);
            vs.pop_back();
        }
        rec(idx+1,vs,cur_s,s);
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> vs;
        rec(0,vs,"",s);
        return ans;
    }
};