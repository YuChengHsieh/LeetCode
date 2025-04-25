#include <map>
#include <vector>
using namespace std;
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            map<int,int> mp;
            for(auto& num: nums){
                mp[num] ++;
            }
            for(auto& item: mp){
                if(item.second%2) return false;
            }
            return true;
        }
    };