#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution {
private:
    int max_val = 0;
    void rec(int idx, set<string>& st, string& s){
        if(idx == s.size()) max_val = max(max_val,(int)st.size());
        int ans = 0;
        string tmp_s;
        for(int i=idx; i<s.size(); i++){
            tmp_s += s[i];
            if(!st.count(tmp_s)){
                st.insert(tmp_s);
                rec(i+1,st,s);
                st.erase(tmp_s);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        rec(0,st,s);
        return max_val;
    }
};