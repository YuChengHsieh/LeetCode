#include <vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cur = 0, n = customers.size();
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0) cur += customers[i];
        }
        for(int i=0; i<minutes; i++){
            if(grumpy[i] == 1) cur += customers[i];
        }

        int ans = cur;
        for(int i=minutes; i<n; i++){
            if(grumpy[i] == 1) cur += customers[i];
            if(grumpy[i-minutes] == 1) cur -= customers[i-minutes];
            ans = max(ans,cur);
        }
        return ans;
    }
};