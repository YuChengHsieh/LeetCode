#include <string>
using namespace std;
class Solution{
    bool isPalindrome(const string& str) {
        int left = 0, right = (int)str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--])
                return false;
        }
        return true;
    }
public:
    int longestPalindrome(string s, string t) {
        int maxLen = 0;
        int n = s.size(), m = t.size();
    
        for (int i=0; i<n; ++i) {
            for(int j=i; j<=n; j++){
                string suffixS = s.substr(i,j-i);
                for (int k=0; k<m; ++k) {
                    for(int l=k; l<=m; l++){
                        string prefixT = t.substr(k, l-k);
                        string combined = suffixS + prefixT;
                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.size());
                        }
                    }
                    
                }
            }
        }
    
        return maxLen;
    }
};
