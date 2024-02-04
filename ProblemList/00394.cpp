#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(auto &ch: s){
            if(ch == ']'){
                string tmp_s;
                int digit = 1, val = 0;
                while(!st.empty() && st.top() != '['){
                    tmp_s = st.top() + tmp_s;
                    st.pop();
                }

                if(!st.empty() && st.top() == '[') st.pop();
                while(!st.empty() && isdigit(st.top())){
                    val += (st.top()-'0')*digit;
                    digit *= 10;
                    st.pop();
                }
                string tmp = tmp_s;
                for(int i=0; i<val-1; i++){
                    tmp_s += tmp;
                }
                // cout << tmp_s << ' ' << val << endl;
                for(auto &ch2: tmp_s){
                    st.push(ch2);
                }

            }else st.push(ch);
        }

        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};