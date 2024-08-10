#include <string>
#include <stack>
using namespace std;

// stack solution
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(ans.size());
            }else if(s[i] == ')'){
                int ret = st.top();
                st.pop();
                reverse(ans.begin()+ret,ans.end());
            }else ans += s[i];
        }
        return ans;
    }
};

// recursion solution
class Solution {
private:
    pair<string,int> rec(int idx, string& s){
        string cur;
        while(idx < s.size()){
            if(s[idx] == '('){
                auto[ret_str, ret_idx] = rec(idx+1,s);
                idx = ret_idx;
                cur += ret_str;
            }else if(s[idx] == ')'){
                reverse(cur.begin(),cur.end());
                return {cur,idx};
            }else cur += s[idx];
            idx += 1;
        }
        return {cur,0};
    }
public:
    string reverseParentheses(string s) {
        return rec(0,s).first;
    }
};