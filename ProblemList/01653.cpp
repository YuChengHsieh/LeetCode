#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> prefix(s.size(), 0), suffix(s.size(),0);
        for(int i=1; i<s.size(); i++){
            prefix[i] = prefix[i-1] + (s[i-1] == 'b');
        }

        for(int i=s.size()-2; i>=0; i--){
            suffix[i] = suffix[i+1] + (s[i+1] == 'a');
        }

        int ans = INT_MAX;
        for(int i=0; i<s.size(); i++){
            ans = min(ans,prefix[i]+suffix[i]);
        }

        return ans;
    }
};