class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        ans = 0
        neg = False
        if dividend < 0:
            dividend = abs(dividend)
            neg = not neg
        if divisor < 0:
            divisor = abs(divisor)
            neg = not neg

        while dividend >= divisor:
            quotient = divisor
            shift = 1
            while dividend > quotient << 1:
                quotient <<= 1
                shift <<= 1
            dividend -= quotient
            ans += shift

        if ans > (1 << 31)-1 and not neg: return (1 << 31)-1
        return -ans if neg else ans
if __name__ == '__main__':
    a = Solution()
    print(a.divide(10,3))
    print(a.divide(7,-3))