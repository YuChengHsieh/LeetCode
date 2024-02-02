#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = ' ';
        int cnt = 0, ans = 0, cursor = 0;
        for(int i=0; i<chars.size(); i++){
            if(prev == chars[i]) cnt += 1;
            else{
                if(cnt > 1){
                    stack<char> st;
                    while(cnt > 0){
                        st.push(cnt%10+'0');
                        cnt /= 10;
                        ans += 1;
                    }
                    while(!st.empty()){
                        chars[cursor] = st.top();
                        st.pop();
                        cursor += 1;
                    }
                }

                chars[cursor] = chars[i];
                cursor += 1;
                cnt = 1;
                ans += 1;
                prev = chars[i];
            }
        }
        if(cnt > 1){
            stack<char> st;
            while(cnt > 0){
                st.push(cnt%10+'0');
                cnt /= 10;
                ans += 1;
            }
            while(!st.empty()){
                chars[cursor] = st.top();
                st.pop();
                cursor += 1;
            }
        }
        return ans;
    }
};