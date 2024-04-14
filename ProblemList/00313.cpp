#include <vector>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        vector<int> idx(sz,0);
        vector<long> ugly(n,INT_MAX);
        ugly[0] = 1;
        for(int i=1; i<n; i++){
            long min_val = INT_MAX;

            for(int j=0; j<sz; j++){
                min_val = min(min_val, ugly[idx[j]]*(long)primes[j]);
            }
            ugly[i] = min_val;
            for(int j=0; j<sz; j++){
                if(min_val == ugly[idx[j]]*(long)primes[j]) idx[j] += 1;
            }
        }
        return (int)ugly[n-1];
    }
};