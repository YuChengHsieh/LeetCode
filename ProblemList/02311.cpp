#include <string>
using namespace std;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int max_bits = 32 - __builtin_clz(k);
        
        reverse(s.begin(), s.end());

        long long sum = 0;
        int bits = 0;
        for(auto& ch: s){
            if(ch == '0') bits ++;
            else{
                if(bits < max_bits && sum + (long long)pow(2,bits) <= k){
                    sum += (long long)pow(2,bits);
                    bits ++;
                }
            }
        }
        return bits;
    }
};