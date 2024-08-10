#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto& d: details){
            if(stoi(d.substr(11,2)) > 60) ans ++;
        }
        return ans;
    }
};