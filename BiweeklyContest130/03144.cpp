#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int inf = 100000000;
    int dp(int idx, int cnt, string& s, vector<int> cnts, vector<int>& mem){
        if(idx >= (int)s.size()) return 0;
        
        if(mem[idx] != -1) return mem[idx];
        int ans = inf;
        for(int h = idx; h < s.size(); h++){
            int val = -1;
            bool success = true;
            cnts[s[h]-'a'] += 1;
            for(int i=0; i<26; i++){

                if(cnts[i] != 0){
                    if(val == -1) val = cnts[i];
                    else if(val != cnts[i]){
                        success = false;
                        break;
                    } 
                } 
            }
            if(success){
                vector<int> new_cnts(26,0);
                ans = min(ans, dp(h+1,h-idx+1,s,new_cnts,mem)+1);
            }  
        }
        
        return mem[idx] = ans;
        
    }
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> cnts(26,0);
        vector<int> mem(s.size(),-1);
        return dp(0,0,s,cnts,mem);
    }
};