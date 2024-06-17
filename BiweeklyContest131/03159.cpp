#include <vector>
using namespace std;
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> check;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == x) check.push_back(i);
        }
        vector<int> ans(queries.size(),-1);
        for(int i=0; i<ans.size(); i++){
            if(queries[i] <= check.size()) ans[i] = check[queries[i]-1];
        }
        return ans;
    }
};