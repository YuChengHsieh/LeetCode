class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            tmp_num = 0
            while num != 0:
                tmp_num += int(num%10)
                num /= 10
            num = tmp_num
        return num

class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0: return 0
        return 1 + (num - 1) % 9