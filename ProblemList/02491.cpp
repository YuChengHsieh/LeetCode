#include <vector>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int val = skill[0] + skill.back(), n = skill.size();
        for(int i=0; i<n/2; i++){
            if(skill[i]+skill[n-i-1] != val) return -1;
            ans += (long long) skill[i] * (long long) skill[n-i-1];
        }
        return ans;
    }
};