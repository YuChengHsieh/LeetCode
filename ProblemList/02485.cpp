class Solution {
public:
    int pivotInteger(int n) {
        int sum1 = 0, sum2 = 0;
        for(int i=1; i<=n ; i++){
            sum2 += i;
        }

        for(int i=1; i<=n; i++){
            if(sum1 == sum2-sum1-i) return i;
            else if(sum1 > sum2) break;
            sum1 += i;
        }

        return -1;
    }
};