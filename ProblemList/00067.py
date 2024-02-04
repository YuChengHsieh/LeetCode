class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sum_str = ''
        carry = False
        a_len = len(a)
        b_len = len(b)
        a = a[::-1]
        b = b[::-1]
        for i in range(max(a_len,b_len)):
            int_a = int(a[i]) if i < a_len else 0
            int_b = int(b[i]) if i < b_len else 0
            sum = int_a+int_b+int(carry)
            if sum >= 2:
                sum %= 2
                carry = True
            else:
                carry = False
            sum_str += str(sum)
        if carry:
            sum_str += '1'
        return sum_str[::-1]
if __name__ == '__main__':
    a = Solution()
    print(a.addBinary('11','1'))
    print(a.addBinary('1010','1011'))
                