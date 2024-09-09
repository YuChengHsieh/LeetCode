#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return vector<vector<int>>();
        vector<vector<int>> ans;
        int idx = 0;
        for(int i=0; i<m; i++){
            vector<int> tmp;
            for(int j=0; j<n; j++){
                tmp.push_back(original[idx++]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};