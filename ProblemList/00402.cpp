#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        // Monotonic stack
        stack<char> st;
        for(auto& digit: num){
            while(!st.empty() && k > 0 && digit < st.top()){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        string ans;
        int zero_cnt = 0;
        while(!st.empty()){
            if(k > 0) k--;
            else if(st.top() == '0') zero_cnt += 1;
            else{
                for(int i=0; i<zero_cnt; i++) ans += '0';
                ans += st.top();
                zero_cnt = 0;
            }
            st.pop();
        }
        
        if(ans.size() == 0) ans += '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};