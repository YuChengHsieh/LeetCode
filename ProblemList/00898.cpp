#include <unordered_set>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, cur, ans;
        for(auto& num: arr){
            cur = {num};
            for(auto& val: prev){
                cur.insert(val|num);
            }
            for(auto& val: cur){
                ans.insert(val);
            }
            prev = cur;
        }
        return ans.size();
    }
};