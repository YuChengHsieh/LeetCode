#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> a(26,-1), b(26,-1);
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a'] = i;
        }
        
        for(int i=0; i<s.size(); i++){
            b[t[i]-'a'] = i;
        }
        
        
        int ans = 0;
        for(int i=0; i<26; i++){
            ans += abs(a[i]-b[i]);
        }
        return ans;
    }
};