class Solution:
    def maxSubarrays(self, nums: list[int]) -> int:
        n = len(nums)
        minimum = nums[0]
        for num in nums[1:]:
            minimum &= num
        if minimum != 0: return 1
        
        cnt = 0; val = (1 << 20)-1
        for num in nums:
            val &= num
            if val == minimum: 
                cnt += 1
                val = (1 << 20)-1
        return cnt 
                

        