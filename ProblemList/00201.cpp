class Solution {
public:
    int rangeBitwiseAnd(long left, long right) {
        // if(left == right) return left;
        for(int i=0; i<32; i++){
            if(left >= (1L << i) && right < (1L << (i+1))){
                long ans = right & left;
                for(int j=0; j<=i; j++){
                    if(right-left >= (1L << j)) ans &= ~(1L << j);
                }
                return (int) ans;
            }else if(left < (1L << i) && right >= (1L << (i+1))) return 0;
        }
        return 0;
    }
};

// easy version
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = right & left;
        for(int i=0; i<32; i++){
            if(right-left >= (1 << i)) ans &= ~(1 << i);
            else break;
        }
        return ans;
    }
};