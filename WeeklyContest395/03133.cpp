// o(n)
class Solution {
public:
    long long minEnd(int n, int x) {
        long long a = x;
        for(int i=n-1; i>0; i--){
            a = (a+1) | x;
        }
        return a;
    }
};

// o(1)
class Solution {
public:
    long long minEnd(int nn, int xx) {
        long long n = nn - 1;
        long long x = xx;

        for(int i=0; i<64; i++){
            if(((1LL << i) & x) == 0){
                x |= (n&1) * (1LL << i);
                n >>= 1;
                if(n == 0) break;
            }
        }
        return x;
    }
};