class Solution {
public:
    char findKthBit(int n, int k) {
        k --;
        int length = 1;
        for(int i=0; i<n; i++){
            if(k < length) break;
            length = 2*length + 1;
        }

        bool flip = false;
        while(k > 0){
            if(k < (length-1)/2){
                length = (length-1)/2;
                continue;
            }
            if(k == length/2) return flip ? '0' : '1';
            k = length-k-1;
            flip = !flip;
            length = (length-1)/2;
        }
        return flip ? '1' : '0';
    }
};