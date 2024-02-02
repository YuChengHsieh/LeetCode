class Solution:
    def minimumArrayLength(self, nums: list[int]) -> int:
        nums.sort()
        
        cnt = 1
        for num in nums[1:]:
            if num == nums[0]: cnt += 1
            else: 
                if num % nums[0] != 0: return 1
        return (cnt+1)//2