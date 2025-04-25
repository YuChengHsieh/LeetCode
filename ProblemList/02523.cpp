#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int n = right;
            vector<bool> is_prime(n+1, true);
            vector<int> primes;
    
            if (n < 2) return {-1,-1};
    
            is_prime[0] = is_prime[1] = false;  
    
            for (int i = 2; i * i <= n; i++) {
                if (is_prime[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        is_prime[j] = false;  
                    }
                }
            }
    
            for (int i = 2; i <= n; i++) {
                if (is_prime[i]) {
                    primes.push_back(i);
                }
            }
    
            int idx = 0;
            while(idx < primes.size() && primes[idx] < left) idx++;
            int min_val = INT_MAX;
            vector<int> ans = {-1,-1};
            for(int i=idx+1; i<primes.size(); i++){
                if(primes[i] - primes[i-1] < min_val){
                    min_val = primes[i] - primes[i-1];
                    ans = {primes[i-1],primes[i]};
                }
            }
            return ans;
        }
    };