class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        max_val = max(nums)
        cnt = max_cnt = 0
        for num in nums:
            if num == max_val: 
                cnt += 1
                if cnt > max_cnt: max_cnt = cnt
            else:
                cnt = 0
        return max_cnt