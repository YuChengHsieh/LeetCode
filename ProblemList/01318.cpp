class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip_cnt = 0;
        for(int i=30; i>=0; i--){
            int check_bit = 1 << i;
            int a_check = a & check_bit, b_check = b & check_bit, c_check = c & check_bit;
            if(c_check != (a_check | b_check)){
                if(c_check == 0){
                    if(a_check != 0 && b_check != 0) flip_cnt += 2;
                    else flip_cnt += 1;
                }else flip_cnt += 1;
            }
        }
        return flip_cnt;
    }
};