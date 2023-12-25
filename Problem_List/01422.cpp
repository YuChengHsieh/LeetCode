#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
    vector<int> num_zeros(s.size()+1,0);
    for(int i=1; i<=s.size(); i++){
        num_zeros[i] = num_zeros[i-1] + int(s[i-1] == '0');
    }

    int num_ones = s.size() - num_zeros[s.size()];
    int ans = 0;
    for(int i=1; i<s.size(); i++){
        ans = max(ans,num_zeros[i]+num_ones-(i-num_zeros[i]));
    }
    return ans;
    }
};