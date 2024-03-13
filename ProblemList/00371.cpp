class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        bool carry = false;
        for(int i=0; i<32; i++){
            bool a_carry = (bool)(a & (1<<i));
            bool b_carry = (bool)(b & (1<<i));
            if(carry){
                if(a_carry && b_carry){
                    carry = true;
                    ans |= (1<<i); 
                }else if(a_carry || b_carry) carry = true;
                else{
                    carry = false;
                    ans |= (1<<i);
                }
            }else{
                if(a_carry && b_carry){
                    carry = true;
                }else if(a_carry || b_carry){
                    carry = false;
                    ans |= (1<<i);
                }
                else carry = false;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int ans;
        while(b != 0){
            ans = (a&b);
            a ^= b;
            // b is carry
            b = (ans << 1); 
        }
        return a;
    }
};