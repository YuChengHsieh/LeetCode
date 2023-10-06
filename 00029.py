class Solution:
    def divide(self, dividend: int, divisor: int) -> int:

        quotient = 0
        sign = -1 if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0) else 1
        dividend,divisor = abs(dividend),abs(divisor)
        
        if sign == 1 and dividend >= 1<<31 and divisor == 1:
            return (1<<31) -1
        elif sign == -1 and dividend < -1 << 31 and divisor == 1:
            return -1 << 31
        
        while dividend >= divisor:
            tmp_quotient = divisor
            shift = 1
            
            while tmp_quotient << 1 <= dividend:
                tmp_quotient <<= 1
                shift <<= 1
            
            dividend -= tmp_quotient
            quotient += shift
            
        return quotient*sign

if __name__ == '__main__':
    a = Solution()
    print(a.divide(10,3))
    print(a.divide(7,-3))