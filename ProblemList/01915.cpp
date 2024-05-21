#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        vector<int> cnts(1024,0);
        cnts[0] = 1;
        int prefix = 0;
        for(int right = 0; right < word.size(); right++){
            prefix ^= (1 << (word[right]-'a'));
            
            ans += cnts[prefix];
            for(int i=0; i<10; i++){
                ans += cnts[(prefix ^ (1 << i))]; 
            }
            cnts[prefix] += 1;
        }
        return ans;
    }
};