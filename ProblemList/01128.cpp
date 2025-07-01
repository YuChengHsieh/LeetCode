#include<vector>
#include<map>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            vector<int> cnts(100,0);
            int ans = 0;
            for(auto& d: dominoes){
                int num = d[0] < d[1] ? d[0]*10 + d[1] : d[1]*10 + d[0];
                ans += cnts[num];
                cnts[num] ++;
            }
            return ans;
        }
    };

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<vector<int>,int> mp;
            int ans = 0;
            for(auto& d: dominoes){
                vector<int> vec(9,0);
                vec[d[0]-1] += 1;
                vec[d[1]-1] += 1;
                ans += mp[vec];
                mp[vec] ++;
            }
            return ans;
        }
    };