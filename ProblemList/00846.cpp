#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz = hand.size();
        if(sz%groupSize != 0) return false;
        map<int,int> mp;
        for(auto& i: hand){
            mp[i] += 1;
        }

        for(int i=0; i<sz/groupSize; i++){
            int prev = -1, cnt = 0;
            for(auto& item: mp){
                if(cnt == groupSize) break;
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