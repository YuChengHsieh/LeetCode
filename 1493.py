class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        max_cnt = 0
        cnt = 0
        next_i = 0
        zero = False
        
        i = 0
        while i < len(nums):
            if nums[i] == 0:
                if zero == False:
                    zero = True
                    next_i = i+1
                    cnt += 1
                    i += 1
                else:
                    max_cnt = max(max_cnt,cnt)
                    zero = False
                    cnt = 0
                    i = next_i
            else:
                cnt += 1
                i += 1
        else:
            max_cnt = max(max_cnt,cnt)
        return max_cnt-1