#include <vector>
#include <numeric>
using namespace std;
class Solution {
private:
    long long check(vector<int>& coins, long long val){
        int m = coins.size();
        int nn = (1 << m);
        long long cnt = 0;
        for (int i = 1; i < nn; i++)
        {
            long long lcmm = 1;
            for (int j = 0; j < m; j++)
            {
                if (i & (1 << j))
                {
                    // lcm : calculates the least common multiple (LCM)
                    lcmm = lcm(lcmm, coins[j]);
                }
            }
            // __builtin_popcount : count the number of 1s in i
            if (__builtin_popcount(i)%2 == 1)
                cnt += val / lcmm;
            else
                cnt -= val / lcmm;
        }
        return cnt;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // binary search
        long long kk = k;
        long long start = 0, end = 1e11;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(check(coins,mid) < kk) start = mid + 1;
            else{
                end = mid - 1;
            }
        }
        return start;
    }
};