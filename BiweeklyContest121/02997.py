class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        
        val = 0
        for num in nums:
            val ^= num
        val ^= k
        
        cnt = 0
        for i in range(20):
            if val&(1 << i) != 0: cnt += 1
        return cnt
            