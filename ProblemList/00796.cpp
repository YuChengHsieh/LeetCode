#include <string>
using namespace std;

// brutal force o(n^2)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string tmp;
        int goal_idx = 0;
        for(int i=0; i<s.size(); i++){
            int idx = i;
            for(int j=0; j<goal.size(); j++){
                if(s[idx] == goal[j]) idx++;
                else break;
            }
            if(s.substr(idx,s.size()-idx)+tmp == goal.substr(idx-i,s.size()-(idx-i))) return true;
            tmp += s[i];
        }
        return false;
    }
};

// KMP o(n)
class Solution {
private:
    vector<int> calLps(string s){
        vector<int> lps(s.size(),0);
        int i = 1, len = 0;
        while(i < s.size()){
            if(s[i] == s[len]){
                len ++;
                lps[i] = len;
                i++;
            }else{
                if(len == 0) i++;
                else len = lps[len-1];
            }
        }
        return lps;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        vector<int> lps = calLps(goal);
        int goal_idx = 0, i = 0;
        while(i < s.size()){
            if(s[i] == goal[goal_idx]){
                goal_idx++;
                i++;
            }else{
                if(goal_idx == 0) i++;
                else goal_idx = lps[goal_idx-1];
            }
        }

        return s.substr(0,s.size()-goal_idx) == goal.substr(goal_idx,s.size()-goal_idx);
    }
};