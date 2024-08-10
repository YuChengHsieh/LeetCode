#include <vector>
using namespace std;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt = 0;
        int n = colors.size();
        if(colors[0] != colors[n-1] && colors[0] != colors[1]) cnt += 1;
        for(int i=1; i<n-1; i++){
            if(colors[i] != colors[i-1] && colors[i] != colors[i+1]) cnt += 1;
        }
        if(colors[n-1] != colors[n-2] && colors[n-1] != colors[0]) cnt += 1;
        return cnt;
    }
};