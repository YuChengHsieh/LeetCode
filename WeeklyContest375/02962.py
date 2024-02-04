class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        # sliding window
        first = ans = cur = 0
        max_ = max(nums)
        for num in nums:
            cur += max_ == num
            while cur >= k:
                cur -= max_ == nums[first]
                first += 1
            ans += first
        return ans