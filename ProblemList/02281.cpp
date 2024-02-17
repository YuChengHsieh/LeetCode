// prefix prefix sum + monotonic stack
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        stack<int> ms;
        int n = strength.size();
        int mod = pow(10,9) + 7;
        
        vector<long long> prefix(n+1, 0L);
        for(int i=1; i<=n; i++){
            prefix[i] = (prefix[i-1] + strength[i-1]) % mod;
        }

        
        vector<long long> prefix_sum(n+2, 0L);
        for(int i=1; i<=n+1; i++){
            prefix_sum[i] = (prefix_sum[i-1] + prefix[i-1]) % mod;
        }
        
        vector<int> right(n,n);
        for(int i=0; i<n; i++){
            while(!ms.empty() && strength[ms.top()] >= strength[i]){
                right[ms.top()] = i;
                ms.pop();
            }
            ms.push(i);
        }

        while(!ms.empty()) ms.pop();
        vector<int> left(n,-1);
        for(int i=n-1; i>=0; i--){
            while(!ms.empty() && strength[ms.top()] > strength[i]){
                left[ms.top()] = i;
                ms.pop();
            }
            ms.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += ((prefix_sum[right[i]+1] - prefix_sum[i+1] )*(i-left[i]) % mod + mod*2 - (prefix_sum[i+1] - prefix_sum[left[i]+1]) * (right[i]-i)% mod ) %mod * strength[i] % mod;
            ans %= mod;
        }
        return int(ans);

    }
};