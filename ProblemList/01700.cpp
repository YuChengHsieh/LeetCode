#include <vector>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2,0);
        for(auto&s: students) counts[s] ++;
        
        int remaining = sandwiches.size();
        for(auto&s: sandwiches){
            if(counts[s] == 0) break;
            // if(remaining-- == 0) break;
            remaining --;
            counts[s] -= 1;
        }
        return remaining;
    }
};