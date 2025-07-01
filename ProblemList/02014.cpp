#include <string>
#include <queue>
using namespace std;
class Solution {
private:
    bool check(string& s, string& target, int k){
        int matches = 0, pos = 0;
        for(auto& ch: s){
            if(ch == target[pos]){
                pos ++;
                if(pos == target.size()){
                    pos = 0;
                    matches ++;
                    if(matches == k) return true;
                }
            }
        }
        return false;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> feq(26,0);
        for(auto& ch: s){
            feq[ch-'a'] ++;
        }

        vector<char> candidates;
        for(int i=0; i<26; i++){
            if(feq[i] >= k) candidates.push_back('a' + i);
        }

        queue<string> q;
        for(auto& ch: candidates){
            q.push(string(1,ch));
        }
        
        string ans;
        while(!q.empty()){
            auto str = q.front();
            q.pop();
            if(str.size() >= ans.size()){
                ans = str;
            }

            for(auto& ch: candidates){
                string next = str+ch;
                if(check(s,next,k)){
                    q.push(next);
                }
            }
        }
        return ans;
    }
};