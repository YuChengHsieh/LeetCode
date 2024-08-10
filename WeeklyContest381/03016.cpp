#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnts(26,0);
        int ans = 0;
        for(auto& ch: word) cnts[ch-'a'] ++;
        sort(cnts.begin(),cnts.end(), [](int a, int b){
            return a > b;
        });

        for(int i=0; i<26; i++){
            ans += cnts[i]*(i/8+1);
        }
        return ans;
    }
};