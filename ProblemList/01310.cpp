#include <vector>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n+1,0);
        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1]^arr[i-1];
        }

        vector<int> ans;
        for(auto& q: queries){
            ans.push_back(prefix[q[1]+1]^prefix[q[0]]);
        }

        return ans;
    }
};