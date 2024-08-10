#include <vector>
using namespace std;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), cnt = 1, ans = 0;
        for(int i=1; i<n; i++){
            if(colors[i] != colors[i-1]){
                cnt += 1;
                if(cnt >= k) ans += 1;
            }else cnt = 1;
        }
        if(colors[n-1] != colors[0]){
            cnt += 1;
            if(cnt >= k) ans += 1;
            for(int i=1; i<k-1; i++){
                if(colors[i] != colors[i-1]){
                    cnt += 1;
                    if(cnt >= k) ans += 1;
                }else cnt = 1;
            }
        }
        return ans;
    }
};