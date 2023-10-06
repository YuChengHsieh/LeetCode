class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        digits_len = len(digits)
        for i in range(digits_len-1,-1,-1):
            digits[i] += 1
            if digits[i] == 10:
                digits[i] = 0
            else:
                break
        else:
            digits.insert(0,1)

        return digits

if __name__ == '__main__':
    a = Solution()
    print(a.plusOne([1,2,3]))
    print(a.plusOne([4,3,2,1]))
    print(a.plusOne([9,9,9,9]))
            
            
            