#include <vector>
using namespace std;
class Solution {
public:
    long long coloredCells(int n) {
        n -= 1;
        long long prev = 0, cur = 1;
        for(int i=1; i<=n; i++){
            prev = cur;
            cur = prev + 4*i;
        }
        return cur;
    }
};