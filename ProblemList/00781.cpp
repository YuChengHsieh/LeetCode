#include <map>
#include <vector>
using namespace std;
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            map<int,int> mp;
            for(auto& num: answers){
                mp[num]++;
            }
            
            int ans = 0;
            for(auto& item: mp){
                ans += ceil((double)item.second/(item.first+1)) * (item.first+1);
            }
            return ans;
        }
    };