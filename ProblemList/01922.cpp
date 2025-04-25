class Solution {
    private:
        int mod = 1e9+7;
        long long power(long long x, long long y){
            if(y == 0) return 1LL;
            long long ret = power(x,y/2);
            if(y%2 == 1) ret = ret*ret*x%mod;
            else ret = ret*ret%mod;
            return ret%mod;
        }
    public:
        int countGoodNumbers(long long n) {
            return power(4,n/2)*power(5,(n+1)/2)%mod;
        }
    }; 