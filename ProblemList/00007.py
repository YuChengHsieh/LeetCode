class Solution:
    def reverse(self, x: int) -> int:
        num = str(x)
        if num[0] == '-':
            num = num[1:]
            num = num[::-1]
            num = -int(num)
        else:
            num = num[::-1]
            num = int(num)
        
        if num < (-1 << 31) or num > ((1 << 31) - 1):
            return 0 
        else:
            return num

if __name__ == '__main__':
    a =Solution()
    print(a.reverse('-120'))