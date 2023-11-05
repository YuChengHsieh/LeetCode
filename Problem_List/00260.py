class Solution:
    def singleNumber(self, nums: list[int]) -> list[int]:
        x = 0 
        for num in nums:
            x ^= num
        
        # divide into two array, one is bit i == 1, one is bit i == 0, every array just have one value appear once 
        for i in range(32):
            if (1<<i) & x != 0: break

        x1,x2 = 0,0
        for num in nums:
            if (1<<i) & num != 0:
                x1 ^= num
            else:
                x2 ^= num
        return [x1,x2]