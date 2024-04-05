class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sumOfDigits = 0;
        int tmp_x = x;
        while(tmp_x != 0){
            sumOfDigits += tmp_x%10;
            tmp_x /= 10;
        }
        return x%sumOfDigits == 0 ? sumOfDigits : -1;
    }
};