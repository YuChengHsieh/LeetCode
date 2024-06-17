#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int i=0; i<hours.size(); i++){
            ans += mp[(24-hours[i]%24)%24];
            mp[hours[i]%24] += 1;
        }
        return ans;
    }
};