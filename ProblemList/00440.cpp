#include <vector>
using namespace std;
class Solution {
private:
    int count(int n, long prefix1, long prefix2){
        int steps = 0;
        while(prefix1 <= n){
            steps += min((long)(n+1),prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0){
            int steps = count(n,cur,cur+1);
            if(steps <= k){
                cur ++;
                k -= steps; 
            }else{
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};