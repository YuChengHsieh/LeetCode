#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz%k != 0) return false;
        map<int,int> mp;
        for(auto& i: nums){
            mp[i] += 1;
        }

        for(int i=0; i<sz/k; i++){
            int prev = -1, cnt = 0;
            for(auto& item: mp){
                if(cnt == k) break;
                if(prev != -1 && item.first - prev != 1) return false;
                prev = item.first;
                item.second --;
                if(item.second == 0) mp.erase(item.first);
                cnt ++;
            }
        }
        return mp.size() == 0;
    }
};