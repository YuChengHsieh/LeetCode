#include <vector>
using namespace std;
 
//  o(n^2)
class Solution {
private:
    int inf = 1000000;
    int dp(int cur, int num, int n, vector<vector<int>>& mem){
        if(cur == n) return 0;
        if(cur > n) return inf;
        if(mem[cur][num] != -1) return mem[cur][num];
        int ans = dp(cur+num,num,n,mem)+1;
        if(cur != num) ans = min(ans, dp(cur,cur,n,mem)+1);
        return mem[cur][num] = ans;
    }
public:
    int minSteps(int n) {
        vector<vector<int>> mem(1000, vector<int>(1000,-1));
        return n == 1 ? 0 : dp(1,1,n,mem)+1;
    }
};

//  o(n)
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int steps = 0;
        int factor = 2;

        while(n > 1){
            while(n%factor == 0){
                steps += factor;
                n /= factor;
            }
            factor ++;
        }

        return steps;
    }
};