class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t cur = 2 << 30;
        while( n != 0 ){
            if( n % 2 == 1 ) ans += cur;
            cur >>= 1;
            n >>= 1;
        }
        return ans;
    }
};