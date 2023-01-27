# Sliding Window
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        left,right = 0,0
        min_len = len(nums)+1
        cur_sum = 0
        while True:
            # print(left,right,cur_sum)
            if cur_sum < target:
                if right == len(nums):
                    break
                cur_sum += nums[right]
                right += 1
            else:
                if right - left < min_len:
                    min_len = right - left
                cur_sum -= nums[left]
                left += 1

        return 0 if min_len == len(nums)+1 else min_len