#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1,0), new_arr(n,0);
        set<char> vowels = {'a','e','i','o','u'};
        for(int i=0; i<n; i++){
            prefix[i+1] = vowels.count(words[i][0]) && vowels.count(words[i].back()) ? prefix[i] + 1 : prefix[i]; 
        }

        vector<int> ans;
        for(auto& q: queries){
            ans.push_back(prefix[q[1]+1] - prefix[q[0]]);
        }
        return ans;
    }
};