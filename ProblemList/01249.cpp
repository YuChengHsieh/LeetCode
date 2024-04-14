#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans = "";
        vector<bool> valid(s.size(),false);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')' && !st.empty()){
                valid[i] = true;
                valid[st.top()] = true;
                st.pop();
            }
        }

        for(int i=0; i<s.size(); i++){
            if((s[i] == ')' || s[i] == '(') && !valid[i]) continue;
            ans += s[i];
        }
        return ans;
    }
};