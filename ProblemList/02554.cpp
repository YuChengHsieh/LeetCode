#include <vector>
using namespace std;
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0, sum = 0, cur = 0, idx = 0;
        sort(banned.begin(), banned.end());
        for(int cur=1; cur<=n; cur++){
            if(idx < banned.size() && cur == banned[idx]){
                while(idx < banned.size() && cur == banned[idx]){
                    idx ++;
                }   
                continue;
            }
            
            sum += cur;
            if(sum > maxSum) break;
            cnt ++;
        }
        return cnt;
    }
};