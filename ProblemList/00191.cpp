class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0; 
        while(n != 0){
            if( n%2 == 1 ) ans += 1;
            n /= 2;
        }
        return ans;
    }
};

// bit flip
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0; 
        while(n != 0){
            n &= (n-1);
            ans += 1;
        }
        return ans;
    }
};