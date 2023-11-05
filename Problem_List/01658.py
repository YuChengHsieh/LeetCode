class Solution:
    # See as maximum subarray (Sliding window problem)
    def minOperations(self, nums: list[int], x: int) -> int:
        total_sum = sum(nums)
        max_sublen = -1; cur_sum = 0
        left = 0
        for right in range(len(nums)):
            cur_sum += nums[right]
            while left <= right and cur_sum > total_sum-x:
                cur_sum -= nums[left]
                left += 1
            if cur_sum == total_sum-x:
                max_sublen = max(max_sublen, right-left+1)
        return -1 if max_sublen == -1 else len(nums) - max_sublen