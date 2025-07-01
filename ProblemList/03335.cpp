#include<string>
#include<vector> 
using namespace std;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> cnts(26,0);
        int mod = 1e9 + 7;
        long long ans = 0;

        for(auto& ch: s){
            cnts[ch-'a'] ++;
        }

        for(int i=0; i<t; i++){
            vector<long long> next(26,0);
            next[0] = cnts[25];
            next[1] = (cnts[0] + cnts[25])%mod;
            for(int j=1; j<25; j++){
                next[j+1] = cnts[j];
            }
            cnts = next;
        }

        for(int i=0; i<26; i++){
            ans += cnts[i];
            ans %= mod;
        }

        return ans;
    }
};