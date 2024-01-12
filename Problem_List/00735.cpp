#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto &as: asteroids){
            // cout << as << ' ' << s.top() << endl;
            if(as < 0 && !s.empty() && s.top() > 0){
                while(!s.empty() && s.top() > 0 && abs(as) > abs(s.top())){
                    s.pop();
                }
                if(s.empty() || s.top() < 0 ) s.push(as);
                else if(abs(as) == abs(s.top())) s.pop();
            }else s.push(as);
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};