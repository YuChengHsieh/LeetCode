#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans = 0, cur = 0;
        map[0] = 0;
        for(int i=0; i<nums.size(); i++){
            cur += nums[i] == 0 ? -1 : 1;
            if(map.count(cur)) ans = max(ans, i+1-map[cur]);
            else map[cur] = i+1;
        }
        return ans;
    }
};